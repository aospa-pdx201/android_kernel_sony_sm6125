/* SPDX-License-Identifier: GPL-2.0 */
/*
 * NOTE: This file has been modified by Sony Corporation.
 * Modifications are Copyright 2018 Sony Corporation,
 * and licensed under the license of the file.
 */
#ifndef __PSTORE_INTERNAL_H__
#define __PSTORE_INTERNAL_H__

#include <linux/types.h>
#include <linux/time.h>
#include <linux/pstore.h>

#define PSTORE_DEFAULT_KMSG_BYTES 10240
extern unsigned long kmsg_bytes;

#ifdef CONFIG_PSTORE_FTRACE
extern void pstore_register_ftrace(void);
extern void pstore_unregister_ftrace(void);
#else
static inline void pstore_register_ftrace(void) {}
static inline void pstore_unregister_ftrace(void) {}
#endif

#ifdef CONFIG_PSTORE_PMSG
extern void pstore_register_pmsg(void);
extern void pstore_unregister_pmsg(void);
extern int pstore_get_pmsg_cnt(void);
#else
static inline void pstore_register_pmsg(void) {}
static inline void pstore_unregister_pmsg(void) {}
static inline void pstore_get_pmsg_cnt(void);
#endif

extern struct pstore_info *psinfo;

extern void	pstore_set_kmsg_bytes(int);
extern void	pstore_get_records(int);
extern void	pstore_get_backend_records(struct pstore_info *psi,
					   struct dentry *root, int quiet);
extern int	pstore_mkfile(struct dentry *root,
			      struct pstore_record *record);
extern bool	pstore_is_mounted(void);
extern void	pstore_record_init(struct pstore_record *record,
				   struct pstore_info *psi);

#endif
