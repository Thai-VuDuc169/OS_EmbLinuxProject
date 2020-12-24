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
	{ 0x1057a2d6, "misc_deregister" },
	{ 0xfe990052, "gpio_free" },
	{ 0xaa2b9926, "gpiod_unexport" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xf7cfb497, "misc_register" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xd3d255e8, "gpiod_to_irq" },
	{ 0xd405fa50, "gpiod_get_raw_value" },
	{ 0xcc977dbf, "gpiod_export" },
	{ 0xced9e687, "gpiod_set_debounce" },
	{ 0x847f05e2, "gpiod_direction_input" },
	{ 0x79f06713, "gpio_to_desc" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0x39eac1e0, "send_sig_info" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xc5850110, "printk" },
	{ 0xd8eec393, "pid_task" },
	{ 0x47c4bc4c, "get_task_pid" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D3306C77F20CA5C0344EB15");
