#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x2a70f0, "gpiod_set_value" },
	{ 0x122c3a7e, "_printk" },
	{ 0xd9ec4b80, "gpio_to_desc" },
	{ 0x35da9ad2, "gpiod_direction_output" },
	{ 0x67d1affd, "gpiod_direction_input" },
	{ 0xca1caeb6, "gpiod_get_value" },
	{ 0xdc43cf22, "param_ops_int" },
	{ 0x39ff040a, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C08C1D9337A4B3CD28D6B51");
