/**
 * @file
 * @brief  The generated interface for the register allocator.
 *          Contains register classes and types and register constraints
 *          for all nodes where constraints were given in spec.
 * @note    DO NOT EDIT THIS FILE, your changes will be lost.
 *          Edit /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/mips/mips_spec.pl instead.
 *          created by: /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/scripts/generate_regalloc_if.pl /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/mips/mips_spec.pl /home/heaven7/heaven7/temp/build-cparser-Desktop_Qt_5_14_2_GCC_64bit-Debug/libfirm/gen/ir/be/mips
 * $date    Mon Aug  8 09:46:25 2022
 */
#include "gen_mips_regalloc_if.h"

#include "mips_bearch_t.h"

const arch_register_req_t mips_class_reg_req_gp = {
	.cls   = &mips_reg_classes[CLASS_mips_gp],
	.width = 1,
};
static const unsigned mips_limited_gp_zero[] = { (1U << REG_GP_ZERO) };
const arch_register_req_t mips_single_reg_req_gp_zero = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_zero,
	.width   = 1,
};
static const unsigned mips_limited_gp_at[] = { (1U << REG_GP_AT) };
const arch_register_req_t mips_single_reg_req_gp_at = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_at,
	.width   = 1,
};
static const unsigned mips_limited_gp_v0[] = { (1U << REG_GP_V0) };
const arch_register_req_t mips_single_reg_req_gp_v0 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_v0,
	.width   = 1,
};
static const unsigned mips_limited_gp_v1[] = { (1U << REG_GP_V1) };
const arch_register_req_t mips_single_reg_req_gp_v1 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_v1,
	.width   = 1,
};
static const unsigned mips_limited_gp_a0[] = { (1U << REG_GP_A0) };
const arch_register_req_t mips_single_reg_req_gp_a0 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_a0,
	.width   = 1,
};
static const unsigned mips_limited_gp_a1[] = { (1U << REG_GP_A1) };
const arch_register_req_t mips_single_reg_req_gp_a1 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_a1,
	.width   = 1,
};
static const unsigned mips_limited_gp_a2[] = { (1U << REG_GP_A2) };
const arch_register_req_t mips_single_reg_req_gp_a2 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_a2,
	.width   = 1,
};
static const unsigned mips_limited_gp_a3[] = { (1U << REG_GP_A3) };
const arch_register_req_t mips_single_reg_req_gp_a3 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_a3,
	.width   = 1,
};
static const unsigned mips_limited_gp_t0[] = { (1U << REG_GP_T0) };
const arch_register_req_t mips_single_reg_req_gp_t0 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_t0,
	.width   = 1,
};
static const unsigned mips_limited_gp_t1[] = { (1U << REG_GP_T1) };
const arch_register_req_t mips_single_reg_req_gp_t1 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_t1,
	.width   = 1,
};
static const unsigned mips_limited_gp_t2[] = { (1U << REG_GP_T2) };
const arch_register_req_t mips_single_reg_req_gp_t2 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_t2,
	.width   = 1,
};
static const unsigned mips_limited_gp_t3[] = { (1U << REG_GP_T3) };
const arch_register_req_t mips_single_reg_req_gp_t3 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_t3,
	.width   = 1,
};
static const unsigned mips_limited_gp_t4[] = { (1U << REG_GP_T4) };
const arch_register_req_t mips_single_reg_req_gp_t4 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_t4,
	.width   = 1,
};
static const unsigned mips_limited_gp_t5[] = { (1U << REG_GP_T5) };
const arch_register_req_t mips_single_reg_req_gp_t5 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_t5,
	.width   = 1,
};
static const unsigned mips_limited_gp_t6[] = { (1U << REG_GP_T6) };
const arch_register_req_t mips_single_reg_req_gp_t6 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_t6,
	.width   = 1,
};
static const unsigned mips_limited_gp_t7[] = { (1U << REG_GP_T7) };
const arch_register_req_t mips_single_reg_req_gp_t7 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_t7,
	.width   = 1,
};
static const unsigned mips_limited_gp_s0[] = { (1U << REG_GP_S0) };
const arch_register_req_t mips_single_reg_req_gp_s0 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_s0,
	.width   = 1,
};
static const unsigned mips_limited_gp_s1[] = { (1U << REG_GP_S1) };
const arch_register_req_t mips_single_reg_req_gp_s1 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_s1,
	.width   = 1,
};
static const unsigned mips_limited_gp_s2[] = { (1U << REG_GP_S2) };
const arch_register_req_t mips_single_reg_req_gp_s2 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_s2,
	.width   = 1,
};
static const unsigned mips_limited_gp_s3[] = { (1U << REG_GP_S3) };
const arch_register_req_t mips_single_reg_req_gp_s3 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_s3,
	.width   = 1,
};
static const unsigned mips_limited_gp_s4[] = { (1U << REG_GP_S4) };
const arch_register_req_t mips_single_reg_req_gp_s4 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_s4,
	.width   = 1,
};
static const unsigned mips_limited_gp_s5[] = { (1U << REG_GP_S5) };
const arch_register_req_t mips_single_reg_req_gp_s5 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_s5,
	.width   = 1,
};
static const unsigned mips_limited_gp_s6[] = { (1U << REG_GP_S6) };
const arch_register_req_t mips_single_reg_req_gp_s6 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_s6,
	.width   = 1,
};
static const unsigned mips_limited_gp_s7[] = { (1U << REG_GP_S7) };
const arch_register_req_t mips_single_reg_req_gp_s7 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_s7,
	.width   = 1,
};
static const unsigned mips_limited_gp_t8[] = { (1U << REG_GP_T8) };
const arch_register_req_t mips_single_reg_req_gp_t8 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_t8,
	.width   = 1,
};
static const unsigned mips_limited_gp_t9[] = { (1U << REG_GP_T9) };
const arch_register_req_t mips_single_reg_req_gp_t9 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_t9,
	.width   = 1,
};
static const unsigned mips_limited_gp_k0[] = { (1U << REG_GP_K0) };
const arch_register_req_t mips_single_reg_req_gp_k0 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_k0,
	.width   = 1,
};
static const unsigned mips_limited_gp_k1[] = { (1U << REG_GP_K1) };
const arch_register_req_t mips_single_reg_req_gp_k1 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_k1,
	.width   = 1,
};
static const unsigned mips_limited_gp_gp[] = { (1U << REG_GP_GP) };
const arch_register_req_t mips_single_reg_req_gp_gp = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_gp,
	.width   = 1,
};
static const unsigned mips_limited_gp_sp[] = { (1U << REG_GP_SP) };
const arch_register_req_t mips_single_reg_req_gp_sp = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_sp,
	.width   = 1,
};
static const unsigned mips_limited_gp_s8[] = { (1U << REG_GP_S8) };
const arch_register_req_t mips_single_reg_req_gp_s8 = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_s8,
	.width   = 1,
};
static const unsigned mips_limited_gp_ra[] = { (1U << REG_GP_RA) };
const arch_register_req_t mips_single_reg_req_gp_ra = {
	.cls     = &mips_reg_classes[CLASS_mips_gp],
	.limited = mips_limited_gp_ra,
	.width   = 1,
};


arch_register_class_t mips_reg_classes[] = {
	{
		.name      = "mips_gp",
		.mode      = NULL,
		.regs      = &mips_registers[REG_ZERO],
		.class_req = &mips_class_reg_req_gp,
		.index     = CLASS_mips_gp,
		.n_regs    = 32,
	},

};

/** The array of all registers in the mips architecture, sorted by its global index.*/
const arch_register_t mips_registers[] = {
	{
		.name         = "zero",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_zero,
		.index        = REG_GP_ZERO,
		.global_index = REG_ZERO,
		.dwarf_number = 0,
		.encoding     = 0,
		.is_virtual   = false,
	},
	{
		.name         = "at",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_at,
		.index        = REG_GP_AT,
		.global_index = REG_AT,
		.dwarf_number = 0,
		.encoding     = 1,
		.is_virtual   = false,
	},
	{
		.name         = "v0",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_v0,
		.index        = REG_GP_V0,
		.global_index = REG_V0,
		.dwarf_number = 0,
		.encoding     = 2,
		.is_virtual   = false,
	},
	{
		.name         = "v1",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_v1,
		.index        = REG_GP_V1,
		.global_index = REG_V1,
		.dwarf_number = 0,
		.encoding     = 3,
		.is_virtual   = false,
	},
	{
		.name         = "a0",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_a0,
		.index        = REG_GP_A0,
		.global_index = REG_A0,
		.dwarf_number = 0,
		.encoding     = 4,
		.is_virtual   = false,
	},
	{
		.name         = "a1",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_a1,
		.index        = REG_GP_A1,
		.global_index = REG_A1,
		.dwarf_number = 0,
		.encoding     = 5,
		.is_virtual   = false,
	},
	{
		.name         = "a2",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_a2,
		.index        = REG_GP_A2,
		.global_index = REG_A2,
		.dwarf_number = 0,
		.encoding     = 6,
		.is_virtual   = false,
	},
	{
		.name         = "a3",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_a3,
		.index        = REG_GP_A3,
		.global_index = REG_A3,
		.dwarf_number = 0,
		.encoding     = 7,
		.is_virtual   = false,
	},
	{
		.name         = "t0",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_t0,
		.index        = REG_GP_T0,
		.global_index = REG_T0,
		.dwarf_number = 0,
		.encoding     = 8,
		.is_virtual   = false,
	},
	{
		.name         = "t1",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_t1,
		.index        = REG_GP_T1,
		.global_index = REG_T1,
		.dwarf_number = 0,
		.encoding     = 9,
		.is_virtual   = false,
	},
	{
		.name         = "t2",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_t2,
		.index        = REG_GP_T2,
		.global_index = REG_T2,
		.dwarf_number = 0,
		.encoding     = 10,
		.is_virtual   = false,
	},
	{
		.name         = "t3",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_t3,
		.index        = REG_GP_T3,
		.global_index = REG_T3,
		.dwarf_number = 0,
		.encoding     = 11,
		.is_virtual   = false,
	},
	{
		.name         = "t4",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_t4,
		.index        = REG_GP_T4,
		.global_index = REG_T4,
		.dwarf_number = 0,
		.encoding     = 12,
		.is_virtual   = false,
	},
	{
		.name         = "t5",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_t5,
		.index        = REG_GP_T5,
		.global_index = REG_T5,
		.dwarf_number = 0,
		.encoding     = 13,
		.is_virtual   = false,
	},
	{
		.name         = "t6",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_t6,
		.index        = REG_GP_T6,
		.global_index = REG_T6,
		.dwarf_number = 0,
		.encoding     = 14,
		.is_virtual   = false,
	},
	{
		.name         = "t7",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_t7,
		.index        = REG_GP_T7,
		.global_index = REG_T7,
		.dwarf_number = 0,
		.encoding     = 15,
		.is_virtual   = false,
	},
	{
		.name         = "s0",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_s0,
		.index        = REG_GP_S0,
		.global_index = REG_S0,
		.dwarf_number = 0,
		.encoding     = 16,
		.is_virtual   = false,
	},
	{
		.name         = "s1",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_s1,
		.index        = REG_GP_S1,
		.global_index = REG_S1,
		.dwarf_number = 0,
		.encoding     = 17,
		.is_virtual   = false,
	},
	{
		.name         = "s2",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_s2,
		.index        = REG_GP_S2,
		.global_index = REG_S2,
		.dwarf_number = 0,
		.encoding     = 18,
		.is_virtual   = false,
	},
	{
		.name         = "s3",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_s3,
		.index        = REG_GP_S3,
		.global_index = REG_S3,
		.dwarf_number = 0,
		.encoding     = 19,
		.is_virtual   = false,
	},
	{
		.name         = "s4",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_s4,
		.index        = REG_GP_S4,
		.global_index = REG_S4,
		.dwarf_number = 0,
		.encoding     = 20,
		.is_virtual   = false,
	},
	{
		.name         = "s5",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_s5,
		.index        = REG_GP_S5,
		.global_index = REG_S5,
		.dwarf_number = 0,
		.encoding     = 21,
		.is_virtual   = false,
	},
	{
		.name         = "s6",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_s6,
		.index        = REG_GP_S6,
		.global_index = REG_S6,
		.dwarf_number = 0,
		.encoding     = 22,
		.is_virtual   = false,
	},
	{
		.name         = "s7",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_s7,
		.index        = REG_GP_S7,
		.global_index = REG_S7,
		.dwarf_number = 0,
		.encoding     = 23,
		.is_virtual   = false,
	},
	{
		.name         = "t8",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_t8,
		.index        = REG_GP_T8,
		.global_index = REG_T8,
		.dwarf_number = 0,
		.encoding     = 24,
		.is_virtual   = false,
	},
	{
		.name         = "t9",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_t9,
		.index        = REG_GP_T9,
		.global_index = REG_T9,
		.dwarf_number = 0,
		.encoding     = 25,
		.is_virtual   = false,
	},
	{
		.name         = "k0",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_k0,
		.index        = REG_GP_K0,
		.global_index = REG_K0,
		.dwarf_number = 0,
		.encoding     = 26,
		.is_virtual   = false,
	},
	{
		.name         = "k1",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_k1,
		.index        = REG_GP_K1,
		.global_index = REG_K1,
		.dwarf_number = 0,
		.encoding     = 27,
		.is_virtual   = false,
	},
	{
		.name         = "gp",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_gp,
		.index        = REG_GP_GP,
		.global_index = REG_GP,
		.dwarf_number = 0,
		.encoding     = 28,
		.is_virtual   = false,
	},
	{
		.name         = "sp",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_sp,
		.index        = REG_GP_SP,
		.global_index = REG_SP,
		.dwarf_number = 0,
		.encoding     = 29,
		.is_virtual   = false,
	},
	{
		.name         = "s8",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_s8,
		.index        = REG_GP_S8,
		.global_index = REG_S8,
		.dwarf_number = 0,
		.encoding     = 30,
		.is_virtual   = false,
	},
	{
		.name         = "ra",
		.cls          = &mips_reg_classes[CLASS_mips_gp],
		.single_req   = &mips_single_reg_req_gp_ra,
		.index        = REG_GP_RA,
		.global_index = REG_RA,
		.dwarf_number = 0,
		.encoding     = 31,
		.is_virtual   = false,
	},

};

/**
 * Initializes mips register classes.
 */
void mips_register_init(void)
{
	mips_reg_classes[CLASS_mips_gp].mode = mode_Iu;

}
