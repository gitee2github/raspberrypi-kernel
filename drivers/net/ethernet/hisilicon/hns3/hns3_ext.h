/* SPDX-License-Identifier: GPL-2.0+ */
/* Copyright (c) 2023 Hisilicon Limited. */

#ifndef __HNS3_EXT_H
#define __HNS3_EXT_H
#include <linux/types.h>
#include "hns3_enet.h"
#include "hnae3_ext.h"

#define HNS3_PFC_STORM_PARA_DIR_RX 0
#define HNS3_PFC_STORM_PARA_DIR_TX 1
#define HNS3_PFC_STORM_PARA_DISABLE 0
#define HNS3_PFC_STORM_PARA_ENABLE 1
#define HNS3_PFC_STORM_PARA_PERIOD_MIN 5
#define HNS3_PFC_STORM_PARA_PERIOD_MAX 2000

int nic_netdev_match_check(struct net_device *netdev);
void nic_chip_recover_handler(struct net_device *ndev,
			      enum hnae3_event_type_custom event_t);
int nic_set_pfc_storm_para(struct net_device *ndev, int dir, int enable,
			   int period_ms, int times, int recovery_period_ms);
int nic_get_pfc_storm_para(struct net_device *ndev, int dir, int *enable,
			   int *period_ms, int *times, int *recovery_period_ms);
int nic_set_notify_pkt_param(struct net_device *ndev,
			     struct hnae3_notify_pkt_param *param);
int nic_set_notify_pkt_start(struct net_device *ndev);
int nic_set_torus_param(struct net_device *ndev, struct hnae3_torus_param *param);
int nic_get_torus_param(struct net_device *ndev, struct hnae3_torus_param *param);
int nic_clean_stats64(struct net_device *ndev, struct rtnl_link_stats64 *stats);
int nic_set_cpu_affinity(struct net_device *ndev, cpumask_t *affinity_mask);
int nic_get_chipid(struct net_device *ndev, u32 *chip_id);
int nic_get_mac_id(struct net_device *ndev, u32 *mac_id);
int nic_get_io_die_id(struct net_device *ndev, u32 *io_die_id);
int nic_get_chip_num(struct net_device *ndev, u32 *chip_num);
int nic_get_io_die_num(struct net_device *ndev, u32 *io_die_num);
int nic_get_port_num_of_die(struct net_device *ndev, u32 *port_num);
int nic_get_port_num_per_chip(struct net_device *ndev, u32 *port_num);
#endif
