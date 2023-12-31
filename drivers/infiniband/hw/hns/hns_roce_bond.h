// SPDX-License-Identifier: GPL-2.0 OR Linux-OpenIB
/*
 * Copyright (c) 2022 Hisilicon Limited.
 */

#ifndef _HNS_ROCE_BOND_H
#define _HNS_ROCE_BOND_H

#include <linux/netdevice.h>
#include <net/bonding.h>

#define ROCE_BOND_FUNC_MAX 4
#define ROCE_BOND_NAME_ID_IDX 9

enum {
	BOND_MODE_1,
	BOND_MODE_2_4,
};

enum bond_support_type {
	BOND_NOT_SUPPORT,
	/*
	 * bond_grp already exists, but in the current
	 * conditions it's no longer supported
	 */
	BOND_EXISTING_NOT_SUPPORT,
	BOND_SUPPORT,
};

enum hns_roce_bond_state {
	HNS_ROCE_BOND_NOT_BONDED,
	HNS_ROCE_BOND_IS_BONDED,
	HNS_ROCE_BOND_REGISTERING,
	HNS_ROCE_BOND_SLAVE_INC,
	HNS_ROCE_BOND_SLAVE_DEC,
	HNS_ROCE_BOND_SLAVE_CHANGESTATE,
};

enum hns_roce_bond_cmd_type {
	HNS_ROCE_SET_BOND,
	HNS_ROCE_CHANGE_BOND,
	HNS_ROCE_CLEAR_BOND,
};

struct hns_roce_func_info {
	struct net_device *net_dev;
	struct hnae3_handle *handle;
	struct netdev_lag_lower_state_info state;
};

struct hns_roce_bond_group {
	struct net_device *upper_dev;
	struct net_device *main_net_dev;
	struct hns_roce_dev *main_hr_dev;
	u8 slave_num;
	u8 active_slave_num;
	u32 slave_map;
	u32 active_slave_map;
	u32 slave_map_diff;
	u8 bond_id;
	struct bonding *bond;
	bool bond_ready;
	enum hns_roce_bond_state bond_state;
	enum netdev_lag_tx_type tx_type;
	/*
	 * A mutex which protect bond_grp info
	 */
	struct mutex bond_mutex;
	struct hns_roce_func_info bond_func_info[ROCE_BOND_FUNC_MAX];
};

int hns_roce_bond_init(struct hns_roce_dev *hr_dev);
int hns_roce_bond_event(struct notifier_block *self,
			unsigned long event, void *ptr);
void hns_roce_cleanup_bond(struct hns_roce_dev *hr_dev);
bool hns_roce_bond_is_active(struct hns_roce_dev *hr_dev);
struct net_device *hns_roce_get_bond_netdev(struct hns_roce_dev *hr_dev);
struct hns_roce_bond_group *hns_roce_get_bond_grp(struct hns_roce_dev *hr_dev);

#endif
