/**
 * @file
 * @brief  The generated interface for the register allocator.
 *          Contains register classes and types and register constraints
 *          for all nodes where constraints were given in spec.
 * @note    DO NOT EDIT THIS FILE, your changes will be lost.
 *          Edit /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/amd64/amd64_spec.pl instead.
 *          created by: /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/scripts/generate_regalloc_if.pl /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/amd64/amd64_spec.pl /home/heaven7/heaven7/temp/build-cparser-Desktop_Qt_5_14_2_GCC_64bit-Debug/libfirm/gen/ir/be/amd64
 * $date    Mon Aug  8 09:46:25 2022
 */
#include "gen_amd64_regalloc_if.h"

#include "amd64_bearch_t.h"

const arch_register_req_t amd64_class_reg_req_flags = {
	.cls   = &amd64_reg_classes[CLASS_amd64_flags],
	.width = 1,
};
static const unsigned amd64_limited_flags_eflags[] = { (1U << REG_FLAGS_EFLAGS) };
const arch_register_req_t amd64_single_reg_req_flags_eflags = {
	.cls     = &amd64_reg_classes[CLASS_amd64_flags],
	.limited = amd64_limited_flags_eflags,
	.width   = 1,
};
const arch_register_req_t amd64_class_reg_req_gp = {
	.cls   = &amd64_reg_classes[CLASS_amd64_gp],
	.width = 1,
};
static const unsigned amd64_limited_gp_rax[] = { (1U << REG_GP_RAX) };
const arch_register_req_t amd64_single_reg_req_gp_rax = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_rax,
	.width   = 1,
};
static const unsigned amd64_limited_gp_rcx[] = { (1U << REG_GP_RCX) };
const arch_register_req_t amd64_single_reg_req_gp_rcx = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_rcx,
	.width   = 1,
};
static const unsigned amd64_limited_gp_rdx[] = { (1U << REG_GP_RDX) };
const arch_register_req_t amd64_single_reg_req_gp_rdx = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_rdx,
	.width   = 1,
};
static const unsigned amd64_limited_gp_rsi[] = { (1U << REG_GP_RSI) };
const arch_register_req_t amd64_single_reg_req_gp_rsi = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_rsi,
	.width   = 1,
};
static const unsigned amd64_limited_gp_rdi[] = { (1U << REG_GP_RDI) };
const arch_register_req_t amd64_single_reg_req_gp_rdi = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_rdi,
	.width   = 1,
};
static const unsigned amd64_limited_gp_rbx[] = { (1U << REG_GP_RBX) };
const arch_register_req_t amd64_single_reg_req_gp_rbx = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_rbx,
	.width   = 1,
};
static const unsigned amd64_limited_gp_rbp[] = { (1U << REG_GP_RBP) };
const arch_register_req_t amd64_single_reg_req_gp_rbp = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_rbp,
	.width   = 1,
};
static const unsigned amd64_limited_gp_rsp[] = { (1U << REG_GP_RSP) };
const arch_register_req_t amd64_single_reg_req_gp_rsp = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_rsp,
	.width   = 1,
};
static const unsigned amd64_limited_gp_r8[] = { (1U << REG_GP_R8) };
const arch_register_req_t amd64_single_reg_req_gp_r8 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_r8,
	.width   = 1,
};
static const unsigned amd64_limited_gp_r9[] = { (1U << REG_GP_R9) };
const arch_register_req_t amd64_single_reg_req_gp_r9 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_r9,
	.width   = 1,
};
static const unsigned amd64_limited_gp_r10[] = { (1U << REG_GP_R10) };
const arch_register_req_t amd64_single_reg_req_gp_r10 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_r10,
	.width   = 1,
};
static const unsigned amd64_limited_gp_r11[] = { (1U << REG_GP_R11) };
const arch_register_req_t amd64_single_reg_req_gp_r11 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_r11,
	.width   = 1,
};
static const unsigned amd64_limited_gp_r12[] = { (1U << REG_GP_R12) };
const arch_register_req_t amd64_single_reg_req_gp_r12 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_r12,
	.width   = 1,
};
static const unsigned amd64_limited_gp_r13[] = { (1U << REG_GP_R13) };
const arch_register_req_t amd64_single_reg_req_gp_r13 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_r13,
	.width   = 1,
};
static const unsigned amd64_limited_gp_r14[] = { (1U << REG_GP_R14) };
const arch_register_req_t amd64_single_reg_req_gp_r14 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_r14,
	.width   = 1,
};
static const unsigned amd64_limited_gp_r15[] = { (1U << REG_GP_R15) };
const arch_register_req_t amd64_single_reg_req_gp_r15 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_gp],
	.limited = amd64_limited_gp_r15,
	.width   = 1,
};
const arch_register_req_t amd64_class_reg_req_x87 = {
	.cls   = &amd64_reg_classes[CLASS_amd64_x87],
	.width = 1,
};
static const unsigned amd64_limited_x87_st0[] = { (1U << REG_X87_ST0) };
const arch_register_req_t amd64_single_reg_req_x87_st0 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_x87],
	.limited = amd64_limited_x87_st0,
	.width   = 1,
};
static const unsigned amd64_limited_x87_st1[] = { (1U << REG_X87_ST1) };
const arch_register_req_t amd64_single_reg_req_x87_st1 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_x87],
	.limited = amd64_limited_x87_st1,
	.width   = 1,
};
static const unsigned amd64_limited_x87_st2[] = { (1U << REG_X87_ST2) };
const arch_register_req_t amd64_single_reg_req_x87_st2 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_x87],
	.limited = amd64_limited_x87_st2,
	.width   = 1,
};
static const unsigned amd64_limited_x87_st3[] = { (1U << REG_X87_ST3) };
const arch_register_req_t amd64_single_reg_req_x87_st3 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_x87],
	.limited = amd64_limited_x87_st3,
	.width   = 1,
};
static const unsigned amd64_limited_x87_st4[] = { (1U << REG_X87_ST4) };
const arch_register_req_t amd64_single_reg_req_x87_st4 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_x87],
	.limited = amd64_limited_x87_st4,
	.width   = 1,
};
static const unsigned amd64_limited_x87_st5[] = { (1U << REG_X87_ST5) };
const arch_register_req_t amd64_single_reg_req_x87_st5 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_x87],
	.limited = amd64_limited_x87_st5,
	.width   = 1,
};
static const unsigned amd64_limited_x87_st6[] = { (1U << REG_X87_ST6) };
const arch_register_req_t amd64_single_reg_req_x87_st6 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_x87],
	.limited = amd64_limited_x87_st6,
	.width   = 1,
};
static const unsigned amd64_limited_x87_st7[] = { (1U << REG_X87_ST7) };
const arch_register_req_t amd64_single_reg_req_x87_st7 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_x87],
	.limited = amd64_limited_x87_st7,
	.width   = 1,
};
const arch_register_req_t amd64_class_reg_req_xmm = {
	.cls   = &amd64_reg_classes[CLASS_amd64_xmm],
	.width = 1,
};
static const unsigned amd64_limited_xmm_xmm0[] = { (1U << REG_XMM_XMM0) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm0 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm0,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm1[] = { (1U << REG_XMM_XMM1) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm1 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm1,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm2[] = { (1U << REG_XMM_XMM2) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm2 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm2,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm3[] = { (1U << REG_XMM_XMM3) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm3 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm3,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm4[] = { (1U << REG_XMM_XMM4) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm4 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm4,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm5[] = { (1U << REG_XMM_XMM5) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm5 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm5,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm6[] = { (1U << REG_XMM_XMM6) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm6 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm6,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm7[] = { (1U << REG_XMM_XMM7) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm7 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm7,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm8[] = { (1U << REG_XMM_XMM8) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm8 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm8,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm9[] = { (1U << REG_XMM_XMM9) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm9 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm9,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm10[] = { (1U << REG_XMM_XMM10) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm10 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm10,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm11[] = { (1U << REG_XMM_XMM11) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm11 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm11,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm12[] = { (1U << REG_XMM_XMM12) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm12 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm12,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm13[] = { (1U << REG_XMM_XMM13) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm13 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm13,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm14[] = { (1U << REG_XMM_XMM14) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm14 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm14,
	.width   = 1,
};
static const unsigned amd64_limited_xmm_xmm15[] = { (1U << REG_XMM_XMM15) };
const arch_register_req_t amd64_single_reg_req_xmm_xmm15 = {
	.cls     = &amd64_reg_classes[CLASS_amd64_xmm],
	.limited = amd64_limited_xmm_xmm15,
	.width   = 1,
};


arch_register_class_t amd64_reg_classes[] = {
	{
		.name      = "amd64_flags",
		.mode      = NULL,
		.regs      = &amd64_registers[REG_EFLAGS],
		.class_req = &amd64_class_reg_req_flags,
		.index     = CLASS_amd64_flags,
		.n_regs    = 1,
		.manual_ra = true,
	},
	{
		.name      = "amd64_gp",
		.mode      = NULL,
		.regs      = &amd64_registers[REG_RAX],
		.class_req = &amd64_class_reg_req_gp,
		.index     = CLASS_amd64_gp,
		.n_regs    = 16,
	},
	{
		.name      = "amd64_x87",
		.mode      = NULL,
		.regs      = &amd64_registers[REG_ST0],
		.class_req = &amd64_class_reg_req_x87,
		.index     = CLASS_amd64_x87,
		.n_regs    = 8,
		.allow_clobber_input = true,
	},
	{
		.name      = "amd64_xmm",
		.mode      = NULL,
		.regs      = &amd64_registers[REG_XMM0],
		.class_req = &amd64_class_reg_req_xmm,
		.index     = CLASS_amd64_xmm,
		.n_regs    = 16,
	},

};

/** The array of all registers in the amd64 architecture, sorted by its global index.*/
const arch_register_t amd64_registers[] = {
	{
		.name         = "eflags",
		.cls          = &amd64_reg_classes[CLASS_amd64_flags],
		.single_req   = &amd64_single_reg_req_flags_eflags,
		.index        = REG_FLAGS_EFLAGS,
		.global_index = REG_EFLAGS,
		.dwarf_number = 49,
		.encoding     = REG_FLAGS_EFLAGS,
		.is_virtual   = false,
	},
	{
		.name         = "rax",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_rax,
		.index        = REG_GP_RAX,
		.global_index = REG_RAX,
		.dwarf_number = 0,
		.encoding     = REG_GP_RAX,
		.is_virtual   = false,
	},
	{
		.name         = "rcx",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_rcx,
		.index        = REG_GP_RCX,
		.global_index = REG_RCX,
		.dwarf_number = 2,
		.encoding     = REG_GP_RCX,
		.is_virtual   = false,
	},
	{
		.name         = "rdx",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_rdx,
		.index        = REG_GP_RDX,
		.global_index = REG_RDX,
		.dwarf_number = 1,
		.encoding     = REG_GP_RDX,
		.is_virtual   = false,
	},
	{
		.name         = "rsi",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_rsi,
		.index        = REG_GP_RSI,
		.global_index = REG_RSI,
		.dwarf_number = 4,
		.encoding     = REG_GP_RSI,
		.is_virtual   = false,
	},
	{
		.name         = "rdi",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_rdi,
		.index        = REG_GP_RDI,
		.global_index = REG_RDI,
		.dwarf_number = 5,
		.encoding     = REG_GP_RDI,
		.is_virtual   = false,
	},
	{
		.name         = "rbx",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_rbx,
		.index        = REG_GP_RBX,
		.global_index = REG_RBX,
		.dwarf_number = 3,
		.encoding     = REG_GP_RBX,
		.is_virtual   = false,
	},
	{
		.name         = "rbp",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_rbp,
		.index        = REG_GP_RBP,
		.global_index = REG_RBP,
		.dwarf_number = 6,
		.encoding     = REG_GP_RBP,
		.is_virtual   = false,
	},
	{
		.name         = "rsp",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_rsp,
		.index        = REG_GP_RSP,
		.global_index = REG_RSP,
		.dwarf_number = 7,
		.encoding     = REG_GP_RSP,
		.is_virtual   = false,
	},
	{
		.name         = "r8",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_r8,
		.index        = REG_GP_R8,
		.global_index = REG_R8,
		.dwarf_number = 8,
		.encoding     = REG_GP_R8,
		.is_virtual   = false,
	},
	{
		.name         = "r9",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_r9,
		.index        = REG_GP_R9,
		.global_index = REG_R9,
		.dwarf_number = 9,
		.encoding     = REG_GP_R9,
		.is_virtual   = false,
	},
	{
		.name         = "r10",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_r10,
		.index        = REG_GP_R10,
		.global_index = REG_R10,
		.dwarf_number = 10,
		.encoding     = REG_GP_R10,
		.is_virtual   = false,
	},
	{
		.name         = "r11",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_r11,
		.index        = REG_GP_R11,
		.global_index = REG_R11,
		.dwarf_number = 11,
		.encoding     = REG_GP_R11,
		.is_virtual   = false,
	},
	{
		.name         = "r12",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_r12,
		.index        = REG_GP_R12,
		.global_index = REG_R12,
		.dwarf_number = 12,
		.encoding     = REG_GP_R12,
		.is_virtual   = false,
	},
	{
		.name         = "r13",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_r13,
		.index        = REG_GP_R13,
		.global_index = REG_R13,
		.dwarf_number = 13,
		.encoding     = REG_GP_R13,
		.is_virtual   = false,
	},
	{
		.name         = "r14",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_r14,
		.index        = REG_GP_R14,
		.global_index = REG_R14,
		.dwarf_number = 14,
		.encoding     = REG_GP_R14,
		.is_virtual   = false,
	},
	{
		.name         = "r15",
		.cls          = &amd64_reg_classes[CLASS_amd64_gp],
		.single_req   = &amd64_single_reg_req_gp_r15,
		.index        = REG_GP_R15,
		.global_index = REG_R15,
		.dwarf_number = 15,
		.encoding     = REG_GP_R15,
		.is_virtual   = false,
	},
	{
		.name         = "st",
		.cls          = &amd64_reg_classes[CLASS_amd64_x87],
		.single_req   = &amd64_single_reg_req_x87_st0,
		.index        = REG_X87_ST0,
		.global_index = REG_ST0,
		.dwarf_number = 11,
		.encoding     = 0,
		.is_virtual   = false,
	},
	{
		.name         = "st(1)",
		.cls          = &amd64_reg_classes[CLASS_amd64_x87],
		.single_req   = &amd64_single_reg_req_x87_st1,
		.index        = REG_X87_ST1,
		.global_index = REG_ST1,
		.dwarf_number = 12,
		.encoding     = 1,
		.is_virtual   = false,
	},
	{
		.name         = "st(2)",
		.cls          = &amd64_reg_classes[CLASS_amd64_x87],
		.single_req   = &amd64_single_reg_req_x87_st2,
		.index        = REG_X87_ST2,
		.global_index = REG_ST2,
		.dwarf_number = 13,
		.encoding     = 2,
		.is_virtual   = false,
	},
	{
		.name         = "st(3)",
		.cls          = &amd64_reg_classes[CLASS_amd64_x87],
		.single_req   = &amd64_single_reg_req_x87_st3,
		.index        = REG_X87_ST3,
		.global_index = REG_ST3,
		.dwarf_number = 14,
		.encoding     = 3,
		.is_virtual   = false,
	},
	{
		.name         = "st(4)",
		.cls          = &amd64_reg_classes[CLASS_amd64_x87],
		.single_req   = &amd64_single_reg_req_x87_st4,
		.index        = REG_X87_ST4,
		.global_index = REG_ST4,
		.dwarf_number = 15,
		.encoding     = 4,
		.is_virtual   = false,
	},
	{
		.name         = "st(5)",
		.cls          = &amd64_reg_classes[CLASS_amd64_x87],
		.single_req   = &amd64_single_reg_req_x87_st5,
		.index        = REG_X87_ST5,
		.global_index = REG_ST5,
		.dwarf_number = 16,
		.encoding     = 5,
		.is_virtual   = false,
	},
	{
		.name         = "st(6)",
		.cls          = &amd64_reg_classes[CLASS_amd64_x87],
		.single_req   = &amd64_single_reg_req_x87_st6,
		.index        = REG_X87_ST6,
		.global_index = REG_ST6,
		.dwarf_number = 17,
		.encoding     = 6,
		.is_virtual   = false,
	},
	{
		.name         = "st(7)",
		.cls          = &amd64_reg_classes[CLASS_amd64_x87],
		.single_req   = &amd64_single_reg_req_x87_st7,
		.index        = REG_X87_ST7,
		.global_index = REG_ST7,
		.dwarf_number = 18,
		.encoding     = 7,
		.is_virtual   = false,
	},
	{
		.name         = "xmm0",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm0,
		.index        = REG_XMM_XMM0,
		.global_index = REG_XMM0,
		.dwarf_number = 17,
		.encoding     = REG_XMM_XMM0,
		.is_virtual   = false,
	},
	{
		.name         = "xmm1",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm1,
		.index        = REG_XMM_XMM1,
		.global_index = REG_XMM1,
		.dwarf_number = 18,
		.encoding     = REG_XMM_XMM1,
		.is_virtual   = false,
	},
	{
		.name         = "xmm2",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm2,
		.index        = REG_XMM_XMM2,
		.global_index = REG_XMM2,
		.dwarf_number = 19,
		.encoding     = REG_XMM_XMM2,
		.is_virtual   = false,
	},
	{
		.name         = "xmm3",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm3,
		.index        = REG_XMM_XMM3,
		.global_index = REG_XMM3,
		.dwarf_number = 20,
		.encoding     = REG_XMM_XMM3,
		.is_virtual   = false,
	},
	{
		.name         = "xmm4",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm4,
		.index        = REG_XMM_XMM4,
		.global_index = REG_XMM4,
		.dwarf_number = 21,
		.encoding     = REG_XMM_XMM4,
		.is_virtual   = false,
	},
	{
		.name         = "xmm5",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm5,
		.index        = REG_XMM_XMM5,
		.global_index = REG_XMM5,
		.dwarf_number = 22,
		.encoding     = REG_XMM_XMM5,
		.is_virtual   = false,
	},
	{
		.name         = "xmm6",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm6,
		.index        = REG_XMM_XMM6,
		.global_index = REG_XMM6,
		.dwarf_number = 23,
		.encoding     = REG_XMM_XMM6,
		.is_virtual   = false,
	},
	{
		.name         = "xmm7",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm7,
		.index        = REG_XMM_XMM7,
		.global_index = REG_XMM7,
		.dwarf_number = 24,
		.encoding     = REG_XMM_XMM7,
		.is_virtual   = false,
	},
	{
		.name         = "xmm8",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm8,
		.index        = REG_XMM_XMM8,
		.global_index = REG_XMM8,
		.dwarf_number = 25,
		.encoding     = REG_XMM_XMM8,
		.is_virtual   = false,
	},
	{
		.name         = "xmm9",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm9,
		.index        = REG_XMM_XMM9,
		.global_index = REG_XMM9,
		.dwarf_number = 26,
		.encoding     = REG_XMM_XMM9,
		.is_virtual   = false,
	},
	{
		.name         = "xmm10",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm10,
		.index        = REG_XMM_XMM10,
		.global_index = REG_XMM10,
		.dwarf_number = 27,
		.encoding     = REG_XMM_XMM10,
		.is_virtual   = false,
	},
	{
		.name         = "xmm11",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm11,
		.index        = REG_XMM_XMM11,
		.global_index = REG_XMM11,
		.dwarf_number = 28,
		.encoding     = REG_XMM_XMM11,
		.is_virtual   = false,
	},
	{
		.name         = "xmm12",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm12,
		.index        = REG_XMM_XMM12,
		.global_index = REG_XMM12,
		.dwarf_number = 29,
		.encoding     = REG_XMM_XMM12,
		.is_virtual   = false,
	},
	{
		.name         = "xmm13",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm13,
		.index        = REG_XMM_XMM13,
		.global_index = REG_XMM13,
		.dwarf_number = 30,
		.encoding     = REG_XMM_XMM13,
		.is_virtual   = false,
	},
	{
		.name         = "xmm14",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm14,
		.index        = REG_XMM_XMM14,
		.global_index = REG_XMM14,
		.dwarf_number = 31,
		.encoding     = REG_XMM_XMM14,
		.is_virtual   = false,
	},
	{
		.name         = "xmm15",
		.cls          = &amd64_reg_classes[CLASS_amd64_xmm],
		.single_req   = &amd64_single_reg_req_xmm_xmm15,
		.index        = REG_XMM_XMM15,
		.global_index = REG_XMM15,
		.dwarf_number = 32,
		.encoding     = REG_XMM_XMM15,
		.is_virtual   = false,
	},

};

/**
 * Initializes amd64 register classes.
 */
void amd64_register_init(void)
{
	amd64_reg_classes[CLASS_amd64_flags].mode = mode_Iu;
	amd64_reg_classes[CLASS_amd64_gp].mode = mode_Lu;
	amd64_reg_classes[CLASS_amd64_x87].mode = x86_mode_E;
	amd64_reg_classes[CLASS_amd64_xmm].mode = amd64_mode_xmm;

}
