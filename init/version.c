/*
 *  linux/init/version.c
 *
 *  Copyright (C) 1992  Theodore Ts'o
 *
 *  May be freely distributed as part of Linux.
 */

#include <generated/compile.h>
#include <linux/module.h>
#include <linux/uts.h>
#include <linux/utsname.h>
#include <generated/utsrelease.h>
#include <linux/version.h>

#ifndef CONFIG_KALLSYMS
#define version(a) Version_ ## a
#define version_string(a) version(a)

extern int version_string(LINUX_VERSION_CODE);
int version_string(LINUX_VERSION_CODE);
#endif

struct uts_namespace init_uts_ns = {
	.kref = {
		.refcount	= ATOMIC_INIT(2),
	},
	.name = {
		.sysname	= UTS_SYSNAME,
		.nodename	= UTS_NODENAME,
		.release	= UTS_RELEASE,
		.version	= UTS_VERSION,
		.machine	= UTS_MACHINE,
		.domainname	= UTS_DOMAINNAME,
	},
};
EXPORT_SYMBOL_GPL(init_uts_ns);

/* FIXED STRINGS! Don't touch! */
const char linux_banner[] =
	"Linux version " UTS_RELEASE " (Bullet"
	") (" LINUX_COMPILER ") " UTS_VERSION "\n";
#if defined(CONFIG_OC_1200MHZ)
const char linux_proc_banner[] =
	"%s version %s"
	" (Bullet-1.2Ghz-RB-v3)"
	" (" LINUX_COMPILER ") %s\n";
#elif defined(CONFIG_OC_1420MHZ)
const char linux_proc_banner[] =
	"%s version %s"
	" (Bullet-1.42Ghz-RB-v3)"
	" (" LINUX_COMPILER ") %s\n";
#elif defined(CONFIG_OC_1540MHZ)
const char linux_proc_banner[] =
	"%s version %s"
	" (Bullet-1.54Ghz-RB-v1.0)"
	" (" LINUX_COMPILER ") %s\n";
#else
const char linux_proc_banner[] =
	"%s version %s"
	" (Bullet-1Ghz-RB-v1.1)"
	" (" LINUX_COMPILER ") %s\n";
#endif
