#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0xe7cc3b88, "module_layout" },
	{ 0x2cfde9a2, "warn_slowpath_fmt" },
	{ 0x5f754e5a, "memset" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x2d6fcc06, "__kmalloc" },
	{ 0xf9a482f9, "msleep" },
	{ 0xde71008, "gpiod_direction_output_raw" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xf63fc023, "sysfs_create_group" },
	{ 0xaf22ee50, "kobject_create_and_add" },
	{ 0xa706a3f8, "kernel_kobj" },
	{ 0xf31494e5, "__register_chrdev" },
	{ 0x8e865d3c, "arm_delay_ops" },
	{ 0x51389e35, "gpiod_set_raw_value" },
	{ 0x79f06713, "gpio_to_desc" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0x37a0cba, "kfree" },
	{ 0xfe990052, "gpio_free" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x22f8c1ca, "kobject_put" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0xc5850110, "printk" },
	{ 0x84b183ae, "strncmp" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7CF221FC04C7EB6F89CC0F2");
