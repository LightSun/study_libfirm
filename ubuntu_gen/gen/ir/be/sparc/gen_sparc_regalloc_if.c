/**
 * @file
 * @brief  The generated interface for the register allocator.
 *          Contains register classes and types and register constraints
 *          for all nodes where constraints were given in spec.
 * @note    DO NOT EDIT THIS FILE, your changes will be lost.
 *          Edit /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/sparc/sparc_spec.pl instead.
 *          created by: /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/scripts/generate_regalloc_if.pl /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/sparc/sparc_spec.pl /home/heaven7/heaven7/temp/build-cparser-Desktop_Qt_5_14_2_GCC_64bit-Debug/libfirm/gen/ir/be/sparc
 * $date    Mon Aug  8 09:46:25 2022
 */
#include "gen_sparc_regalloc_if.h"

#include "sparc_bearch_t.h"

const arch_register_req_t sparc_class_reg_req_flags = {
	.cls   = &sparc_reg_classes[CLASS_sparc_flags],
	.width = 1,
};
static const unsigned sparc_limited_flags_psr[] = { (1U << REG_FLAGS_PSR) };
const arch_register_req_t sparc_single_reg_req_flags_psr = {
	.cls     = &sparc_reg_classes[CLASS_sparc_flags],
	.limited = sparc_limited_flags_psr,
	.width   = 1,
};
const arch_register_req_t sparc_class_reg_req_fp = {
	.cls   = &sparc_reg_classes[CLASS_sparc_fp],
	.width = 1,
};
static const unsigned sparc_limited_fp_f0[] = { (1U << REG_FP_F0) };
const arch_register_req_t sparc_single_reg_req_fp_f0 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f0,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f1[] = { (1U << REG_FP_F1) };
const arch_register_req_t sparc_single_reg_req_fp_f1 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f1,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f2[] = { (1U << REG_FP_F2) };
const arch_register_req_t sparc_single_reg_req_fp_f2 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f2,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f3[] = { (1U << REG_FP_F3) };
const arch_register_req_t sparc_single_reg_req_fp_f3 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f3,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f4[] = { (1U << REG_FP_F4) };
const arch_register_req_t sparc_single_reg_req_fp_f4 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f4,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f5[] = { (1U << REG_FP_F5) };
const arch_register_req_t sparc_single_reg_req_fp_f5 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f5,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f6[] = { (1U << REG_FP_F6) };
const arch_register_req_t sparc_single_reg_req_fp_f6 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f6,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f7[] = { (1U << REG_FP_F7) };
const arch_register_req_t sparc_single_reg_req_fp_f7 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f7,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f8[] = { (1U << REG_FP_F8) };
const arch_register_req_t sparc_single_reg_req_fp_f8 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f8,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f9[] = { (1U << REG_FP_F9) };
const arch_register_req_t sparc_single_reg_req_fp_f9 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f9,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f10[] = { (1U << REG_FP_F10) };
const arch_register_req_t sparc_single_reg_req_fp_f10 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f10,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f11[] = { (1U << REG_FP_F11) };
const arch_register_req_t sparc_single_reg_req_fp_f11 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f11,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f12[] = { (1U << REG_FP_F12) };
const arch_register_req_t sparc_single_reg_req_fp_f12 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f12,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f13[] = { (1U << REG_FP_F13) };
const arch_register_req_t sparc_single_reg_req_fp_f13 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f13,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f14[] = { (1U << REG_FP_F14) };
const arch_register_req_t sparc_single_reg_req_fp_f14 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f14,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f15[] = { (1U << REG_FP_F15) };
const arch_register_req_t sparc_single_reg_req_fp_f15 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f15,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f16[] = { (1U << REG_FP_F16) };
const arch_register_req_t sparc_single_reg_req_fp_f16 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f16,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f17[] = { (1U << REG_FP_F17) };
const arch_register_req_t sparc_single_reg_req_fp_f17 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f17,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f18[] = { (1U << REG_FP_F18) };
const arch_register_req_t sparc_single_reg_req_fp_f18 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f18,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f19[] = { (1U << REG_FP_F19) };
const arch_register_req_t sparc_single_reg_req_fp_f19 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f19,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f20[] = { (1U << REG_FP_F20) };
const arch_register_req_t sparc_single_reg_req_fp_f20 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f20,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f21[] = { (1U << REG_FP_F21) };
const arch_register_req_t sparc_single_reg_req_fp_f21 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f21,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f22[] = { (1U << REG_FP_F22) };
const arch_register_req_t sparc_single_reg_req_fp_f22 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f22,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f23[] = { (1U << REG_FP_F23) };
const arch_register_req_t sparc_single_reg_req_fp_f23 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f23,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f24[] = { (1U << REG_FP_F24) };
const arch_register_req_t sparc_single_reg_req_fp_f24 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f24,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f25[] = { (1U << REG_FP_F25) };
const arch_register_req_t sparc_single_reg_req_fp_f25 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f25,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f26[] = { (1U << REG_FP_F26) };
const arch_register_req_t sparc_single_reg_req_fp_f26 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f26,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f27[] = { (1U << REG_FP_F27) };
const arch_register_req_t sparc_single_reg_req_fp_f27 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f27,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f28[] = { (1U << REG_FP_F28) };
const arch_register_req_t sparc_single_reg_req_fp_f28 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f28,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f29[] = { (1U << REG_FP_F29) };
const arch_register_req_t sparc_single_reg_req_fp_f29 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f29,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f30[] = { (1U << REG_FP_F30) };
const arch_register_req_t sparc_single_reg_req_fp_f30 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f30,
	.width   = 1,
};
static const unsigned sparc_limited_fp_f31[] = { (1U << REG_FP_F31) };
const arch_register_req_t sparc_single_reg_req_fp_f31 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fp],
	.limited = sparc_limited_fp_f31,
	.width   = 1,
};
const arch_register_req_t sparc_class_reg_req_fpflags = {
	.cls   = &sparc_reg_classes[CLASS_sparc_fpflags],
	.width = 1,
};
static const unsigned sparc_limited_fpflags_fsr[] = { (1U << REG_FPFLAGS_FSR) };
const arch_register_req_t sparc_single_reg_req_fpflags_fsr = {
	.cls     = &sparc_reg_classes[CLASS_sparc_fpflags],
	.limited = sparc_limited_fpflags_fsr,
	.width   = 1,
};
const arch_register_req_t sparc_class_reg_req_gp = {
	.cls   = &sparc_reg_classes[CLASS_sparc_gp],
	.width = 1,
};
static const unsigned sparc_limited_gp_l0[] = { (1U << REG_GP_L0) };
const arch_register_req_t sparc_single_reg_req_gp_l0 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_l0,
	.width   = 1,
};
static const unsigned sparc_limited_gp_l1[] = { (1U << REG_GP_L1) };
const arch_register_req_t sparc_single_reg_req_gp_l1 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_l1,
	.width   = 1,
};
static const unsigned sparc_limited_gp_l2[] = { (1U << REG_GP_L2) };
const arch_register_req_t sparc_single_reg_req_gp_l2 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_l2,
	.width   = 1,
};
static const unsigned sparc_limited_gp_l3[] = { (1U << REG_GP_L3) };
const arch_register_req_t sparc_single_reg_req_gp_l3 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_l3,
	.width   = 1,
};
static const unsigned sparc_limited_gp_l4[] = { (1U << REG_GP_L4) };
const arch_register_req_t sparc_single_reg_req_gp_l4 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_l4,
	.width   = 1,
};
static const unsigned sparc_limited_gp_l5[] = { (1U << REG_GP_L5) };
const arch_register_req_t sparc_single_reg_req_gp_l5 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_l5,
	.width   = 1,
};
static const unsigned sparc_limited_gp_l6[] = { (1U << REG_GP_L6) };
const arch_register_req_t sparc_single_reg_req_gp_l6 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_l6,
	.width   = 1,
};
static const unsigned sparc_limited_gp_l7[] = { (1U << REG_GP_L7) };
const arch_register_req_t sparc_single_reg_req_gp_l7 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_l7,
	.width   = 1,
};
static const unsigned sparc_limited_gp_g0[] = { (1U << REG_GP_G0) };
const arch_register_req_t sparc_single_reg_req_gp_g0 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_g0,
	.width   = 1,
};
static const unsigned sparc_limited_gp_g1[] = { (1U << REG_GP_G1) };
const arch_register_req_t sparc_single_reg_req_gp_g1 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_g1,
	.width   = 1,
};
static const unsigned sparc_limited_gp_g2[] = { (1U << REG_GP_G2) };
const arch_register_req_t sparc_single_reg_req_gp_g2 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_g2,
	.width   = 1,
};
static const unsigned sparc_limited_gp_g3[] = { (1U << REG_GP_G3) };
const arch_register_req_t sparc_single_reg_req_gp_g3 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_g3,
	.width   = 1,
};
static const unsigned sparc_limited_gp_g4[] = { (1U << REG_GP_G4) };
const arch_register_req_t sparc_single_reg_req_gp_g4 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_g4,
	.width   = 1,
};
static const unsigned sparc_limited_gp_g5[] = { (1U << REG_GP_G5) };
const arch_register_req_t sparc_single_reg_req_gp_g5 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_g5,
	.width   = 1,
};
static const unsigned sparc_limited_gp_g6[] = { (1U << REG_GP_G6) };
const arch_register_req_t sparc_single_reg_req_gp_g6 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_g6,
	.width   = 1,
};
static const unsigned sparc_limited_gp_g7[] = { (1U << REG_GP_G7) };
const arch_register_req_t sparc_single_reg_req_gp_g7 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_g7,
	.width   = 1,
};
static const unsigned sparc_limited_gp_o0[] = { (1U << REG_GP_O0) };
const arch_register_req_t sparc_single_reg_req_gp_o0 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_o0,
	.width   = 1,
};
static const unsigned sparc_limited_gp_o1[] = { (1U << REG_GP_O1) };
const arch_register_req_t sparc_single_reg_req_gp_o1 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_o1,
	.width   = 1,
};
static const unsigned sparc_limited_gp_o2[] = { (1U << REG_GP_O2) };
const arch_register_req_t sparc_single_reg_req_gp_o2 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_o2,
	.width   = 1,
};
static const unsigned sparc_limited_gp_o3[] = { (1U << REG_GP_O3) };
const arch_register_req_t sparc_single_reg_req_gp_o3 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_o3,
	.width   = 1,
};
static const unsigned sparc_limited_gp_o4[] = { (1U << REG_GP_O4) };
const arch_register_req_t sparc_single_reg_req_gp_o4 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_o4,
	.width   = 1,
};
static const unsigned sparc_limited_gp_o5[] = { (1U << REG_GP_O5) };
const arch_register_req_t sparc_single_reg_req_gp_o5 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_o5,
	.width   = 1,
};
static const unsigned sparc_limited_gp_sp[] = { (1U << REG_GP_SP) };
const arch_register_req_t sparc_single_reg_req_gp_sp = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_sp,
	.width   = 1,
};
static const unsigned sparc_limited_gp_o7[] = { (1U << REG_GP_O7) };
const arch_register_req_t sparc_single_reg_req_gp_o7 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_o7,
	.width   = 1,
};
static const unsigned sparc_limited_gp_i0[] = { (1U << REG_GP_I0) };
const arch_register_req_t sparc_single_reg_req_gp_i0 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_i0,
	.width   = 1,
};
static const unsigned sparc_limited_gp_i1[] = { (1U << REG_GP_I1) };
const arch_register_req_t sparc_single_reg_req_gp_i1 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_i1,
	.width   = 1,
};
static const unsigned sparc_limited_gp_i2[] = { (1U << REG_GP_I2) };
const arch_register_req_t sparc_single_reg_req_gp_i2 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_i2,
	.width   = 1,
};
static const unsigned sparc_limited_gp_i3[] = { (1U << REG_GP_I3) };
const arch_register_req_t sparc_single_reg_req_gp_i3 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_i3,
	.width   = 1,
};
static const unsigned sparc_limited_gp_i4[] = { (1U << REG_GP_I4) };
const arch_register_req_t sparc_single_reg_req_gp_i4 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_i4,
	.width   = 1,
};
static const unsigned sparc_limited_gp_i5[] = { (1U << REG_GP_I5) };
const arch_register_req_t sparc_single_reg_req_gp_i5 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_i5,
	.width   = 1,
};
static const unsigned sparc_limited_gp_fp[] = { (1U << REG_GP_FP) };
const arch_register_req_t sparc_single_reg_req_gp_fp = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_fp,
	.width   = 1,
};
static const unsigned sparc_limited_gp_i7[] = { (1U << REG_GP_I7) };
const arch_register_req_t sparc_single_reg_req_gp_i7 = {
	.cls     = &sparc_reg_classes[CLASS_sparc_gp],
	.limited = sparc_limited_gp_i7,
	.width   = 1,
};
const arch_register_req_t sparc_class_reg_req_mul_div_high_res = {
	.cls   = &sparc_reg_classes[CLASS_sparc_mul_div_high_res],
	.width = 1,
};
static const unsigned sparc_limited_mul_div_high_res_y[] = { (1U << REG_MUL_DIV_HIGH_RES_Y) };
const arch_register_req_t sparc_single_reg_req_mul_div_high_res_y = {
	.cls     = &sparc_reg_classes[CLASS_sparc_mul_div_high_res],
	.limited = sparc_limited_mul_div_high_res_y,
	.width   = 1,
};


arch_register_class_t sparc_reg_classes[] = {
	{
		.name      = "sparc_flags",
		.mode      = NULL,
		.regs      = &sparc_registers[REG_PSR],
		.class_req = &sparc_class_reg_req_flags,
		.index     = CLASS_sparc_flags,
		.n_regs    = 1,
		.manual_ra = true,
	},
	{
		.name      = "sparc_fp",
		.mode      = NULL,
		.regs      = &sparc_registers[REG_F0],
		.class_req = &sparc_class_reg_req_fp,
		.index     = CLASS_sparc_fp,
		.n_regs    = 32,
	},
	{
		.name      = "sparc_fpflags",
		.mode      = NULL,
		.regs      = &sparc_registers[REG_FSR],
		.class_req = &sparc_class_reg_req_fpflags,
		.index     = CLASS_sparc_fpflags,
		.n_regs    = 1,
		.manual_ra = true,
	},
	{
		.name      = "sparc_gp",
		.mode      = NULL,
		.regs      = &sparc_registers[REG_L0],
		.class_req = &sparc_class_reg_req_gp,
		.index     = CLASS_sparc_gp,
		.n_regs    = 32,
	},
	{
		.name      = "sparc_mul_div_high_res",
		.mode      = NULL,
		.regs      = &sparc_registers[REG_Y],
		.class_req = &sparc_class_reg_req_mul_div_high_res,
		.index     = CLASS_sparc_mul_div_high_res,
		.n_regs    = 1,
		.manual_ra = true,
	},

};

/** The array of all registers in the sparc architecture, sorted by its global index.*/
const arch_register_t sparc_registers[] = {
	{
		.name         = "psr",
		.cls          = &sparc_reg_classes[CLASS_sparc_flags],
		.single_req   = &sparc_single_reg_req_flags_psr,
		.index        = REG_FLAGS_PSR,
		.global_index = REG_PSR,
		.dwarf_number = 0,
		.encoding     = REG_FLAGS_PSR,
		.is_virtual   = false,
	},
	{
		.name         = "f0",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f0,
		.index        = REG_FP_F0,
		.global_index = REG_F0,
		.dwarf_number = 32,
		.encoding     = 0,
		.is_virtual   = false,
	},
	{
		.name         = "f1",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f1,
		.index        = REG_FP_F1,
		.global_index = REG_F1,
		.dwarf_number = 33,
		.encoding     = 1,
		.is_virtual   = false,
	},
	{
		.name         = "f2",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f2,
		.index        = REG_FP_F2,
		.global_index = REG_F2,
		.dwarf_number = 34,
		.encoding     = 2,
		.is_virtual   = false,
	},
	{
		.name         = "f3",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f3,
		.index        = REG_FP_F3,
		.global_index = REG_F3,
		.dwarf_number = 35,
		.encoding     = 3,
		.is_virtual   = false,
	},
	{
		.name         = "f4",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f4,
		.index        = REG_FP_F4,
		.global_index = REG_F4,
		.dwarf_number = 36,
		.encoding     = 4,
		.is_virtual   = false,
	},
	{
		.name         = "f5",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f5,
		.index        = REG_FP_F5,
		.global_index = REG_F5,
		.dwarf_number = 37,
		.encoding     = 5,
		.is_virtual   = false,
	},
	{
		.name         = "f6",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f6,
		.index        = REG_FP_F6,
		.global_index = REG_F6,
		.dwarf_number = 38,
		.encoding     = 6,
		.is_virtual   = false,
	},
	{
		.name         = "f7",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f7,
		.index        = REG_FP_F7,
		.global_index = REG_F7,
		.dwarf_number = 39,
		.encoding     = 7,
		.is_virtual   = false,
	},
	{
		.name         = "f8",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f8,
		.index        = REG_FP_F8,
		.global_index = REG_F8,
		.dwarf_number = 40,
		.encoding     = 8,
		.is_virtual   = false,
	},
	{
		.name         = "f9",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f9,
		.index        = REG_FP_F9,
		.global_index = REG_F9,
		.dwarf_number = 41,
		.encoding     = 9,
		.is_virtual   = false,
	},
	{
		.name         = "f10",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f10,
		.index        = REG_FP_F10,
		.global_index = REG_F10,
		.dwarf_number = 42,
		.encoding     = 10,
		.is_virtual   = false,
	},
	{
		.name         = "f11",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f11,
		.index        = REG_FP_F11,
		.global_index = REG_F11,
		.dwarf_number = 43,
		.encoding     = 11,
		.is_virtual   = false,
	},
	{
		.name         = "f12",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f12,
		.index        = REG_FP_F12,
		.global_index = REG_F12,
		.dwarf_number = 44,
		.encoding     = 12,
		.is_virtual   = false,
	},
	{
		.name         = "f13",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f13,
		.index        = REG_FP_F13,
		.global_index = REG_F13,
		.dwarf_number = 45,
		.encoding     = 13,
		.is_virtual   = false,
	},
	{
		.name         = "f14",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f14,
		.index        = REG_FP_F14,
		.global_index = REG_F14,
		.dwarf_number = 46,
		.encoding     = 14,
		.is_virtual   = false,
	},
	{
		.name         = "f15",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f15,
		.index        = REG_FP_F15,
		.global_index = REG_F15,
		.dwarf_number = 47,
		.encoding     = 15,
		.is_virtual   = false,
	},
	{
		.name         = "f16",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f16,
		.index        = REG_FP_F16,
		.global_index = REG_F16,
		.dwarf_number = 48,
		.encoding     = 16,
		.is_virtual   = false,
	},
	{
		.name         = "f17",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f17,
		.index        = REG_FP_F17,
		.global_index = REG_F17,
		.dwarf_number = 49,
		.encoding     = 17,
		.is_virtual   = false,
	},
	{
		.name         = "f18",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f18,
		.index        = REG_FP_F18,
		.global_index = REG_F18,
		.dwarf_number = 50,
		.encoding     = 18,
		.is_virtual   = false,
	},
	{
		.name         = "f19",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f19,
		.index        = REG_FP_F19,
		.global_index = REG_F19,
		.dwarf_number = 51,
		.encoding     = 19,
		.is_virtual   = false,
	},
	{
		.name         = "f20",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f20,
		.index        = REG_FP_F20,
		.global_index = REG_F20,
		.dwarf_number = 52,
		.encoding     = 20,
		.is_virtual   = false,
	},
	{
		.name         = "f21",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f21,
		.index        = REG_FP_F21,
		.global_index = REG_F21,
		.dwarf_number = 53,
		.encoding     = 21,
		.is_virtual   = false,
	},
	{
		.name         = "f22",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f22,
		.index        = REG_FP_F22,
		.global_index = REG_F22,
		.dwarf_number = 54,
		.encoding     = 22,
		.is_virtual   = false,
	},
	{
		.name         = "f23",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f23,
		.index        = REG_FP_F23,
		.global_index = REG_F23,
		.dwarf_number = 55,
		.encoding     = 23,
		.is_virtual   = false,
	},
	{
		.name         = "f24",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f24,
		.index        = REG_FP_F24,
		.global_index = REG_F24,
		.dwarf_number = 56,
		.encoding     = 24,
		.is_virtual   = false,
	},
	{
		.name         = "f25",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f25,
		.index        = REG_FP_F25,
		.global_index = REG_F25,
		.dwarf_number = 57,
		.encoding     = 25,
		.is_virtual   = false,
	},
	{
		.name         = "f26",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f26,
		.index        = REG_FP_F26,
		.global_index = REG_F26,
		.dwarf_number = 58,
		.encoding     = 26,
		.is_virtual   = false,
	},
	{
		.name         = "f27",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f27,
		.index        = REG_FP_F27,
		.global_index = REG_F27,
		.dwarf_number = 59,
		.encoding     = 27,
		.is_virtual   = false,
	},
	{
		.name         = "f28",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f28,
		.index        = REG_FP_F28,
		.global_index = REG_F28,
		.dwarf_number = 60,
		.encoding     = 28,
		.is_virtual   = false,
	},
	{
		.name         = "f29",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f29,
		.index        = REG_FP_F29,
		.global_index = REG_F29,
		.dwarf_number = 61,
		.encoding     = 29,
		.is_virtual   = false,
	},
	{
		.name         = "f30",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f30,
		.index        = REG_FP_F30,
		.global_index = REG_F30,
		.dwarf_number = 62,
		.encoding     = 30,
		.is_virtual   = false,
	},
	{
		.name         = "f31",
		.cls          = &sparc_reg_classes[CLASS_sparc_fp],
		.single_req   = &sparc_single_reg_req_fp_f31,
		.index        = REG_FP_F31,
		.global_index = REG_F31,
		.dwarf_number = 63,
		.encoding     = 31,
		.is_virtual   = false,
	},
	{
		.name         = "fsr",
		.cls          = &sparc_reg_classes[CLASS_sparc_fpflags],
		.single_req   = &sparc_single_reg_req_fpflags_fsr,
		.index        = REG_FPFLAGS_FSR,
		.global_index = REG_FSR,
		.dwarf_number = 0,
		.encoding     = REG_FPFLAGS_FSR,
		.is_virtual   = false,
	},
	{
		.name         = "l0",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_l0,
		.index        = REG_GP_L0,
		.global_index = REG_L0,
		.dwarf_number = 16,
		.encoding     = 16,
		.is_virtual   = false,
	},
	{
		.name         = "l1",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_l1,
		.index        = REG_GP_L1,
		.global_index = REG_L1,
		.dwarf_number = 17,
		.encoding     = 17,
		.is_virtual   = false,
	},
	{
		.name         = "l2",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_l2,
		.index        = REG_GP_L2,
		.global_index = REG_L2,
		.dwarf_number = 18,
		.encoding     = 18,
		.is_virtual   = false,
	},
	{
		.name         = "l3",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_l3,
		.index        = REG_GP_L3,
		.global_index = REG_L3,
		.dwarf_number = 19,
		.encoding     = 19,
		.is_virtual   = false,
	},
	{
		.name         = "l4",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_l4,
		.index        = REG_GP_L4,
		.global_index = REG_L4,
		.dwarf_number = 20,
		.encoding     = 20,
		.is_virtual   = false,
	},
	{
		.name         = "l5",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_l5,
		.index        = REG_GP_L5,
		.global_index = REG_L5,
		.dwarf_number = 21,
		.encoding     = 21,
		.is_virtual   = false,
	},
	{
		.name         = "l6",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_l6,
		.index        = REG_GP_L6,
		.global_index = REG_L6,
		.dwarf_number = 22,
		.encoding     = 22,
		.is_virtual   = false,
	},
	{
		.name         = "l7",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_l7,
		.index        = REG_GP_L7,
		.global_index = REG_L7,
		.dwarf_number = 23,
		.encoding     = 23,
		.is_virtual   = false,
	},
	{
		.name         = "g0",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_g0,
		.index        = REG_GP_G0,
		.global_index = REG_G0,
		.dwarf_number = 0,
		.encoding     = 0,
		.is_virtual   = false,
	},
	{
		.name         = "g1",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_g1,
		.index        = REG_GP_G1,
		.global_index = REG_G1,
		.dwarf_number = 1,
		.encoding     = 1,
		.is_virtual   = false,
	},
	{
		.name         = "g2",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_g2,
		.index        = REG_GP_G2,
		.global_index = REG_G2,
		.dwarf_number = 2,
		.encoding     = 2,
		.is_virtual   = false,
	},
	{
		.name         = "g3",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_g3,
		.index        = REG_GP_G3,
		.global_index = REG_G3,
		.dwarf_number = 3,
		.encoding     = 3,
		.is_virtual   = false,
	},
	{
		.name         = "g4",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_g4,
		.index        = REG_GP_G4,
		.global_index = REG_G4,
		.dwarf_number = 4,
		.encoding     = 4,
		.is_virtual   = false,
	},
	{
		.name         = "g5",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_g5,
		.index        = REG_GP_G5,
		.global_index = REG_G5,
		.dwarf_number = 5,
		.encoding     = 5,
		.is_virtual   = false,
	},
	{
		.name         = "g6",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_g6,
		.index        = REG_GP_G6,
		.global_index = REG_G6,
		.dwarf_number = 6,
		.encoding     = 6,
		.is_virtual   = false,
	},
	{
		.name         = "g7",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_g7,
		.index        = REG_GP_G7,
		.global_index = REG_G7,
		.dwarf_number = 7,
		.encoding     = 7,
		.is_virtual   = false,
	},
	{
		.name         = "o0",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_o0,
		.index        = REG_GP_O0,
		.global_index = REG_O0,
		.dwarf_number = 8,
		.encoding     = 8,
		.is_virtual   = false,
	},
	{
		.name         = "o1",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_o1,
		.index        = REG_GP_O1,
		.global_index = REG_O1,
		.dwarf_number = 9,
		.encoding     = 9,
		.is_virtual   = false,
	},
	{
		.name         = "o2",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_o2,
		.index        = REG_GP_O2,
		.global_index = REG_O2,
		.dwarf_number = 10,
		.encoding     = 10,
		.is_virtual   = false,
	},
	{
		.name         = "o3",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_o3,
		.index        = REG_GP_O3,
		.global_index = REG_O3,
		.dwarf_number = 11,
		.encoding     = 11,
		.is_virtual   = false,
	},
	{
		.name         = "o4",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_o4,
		.index        = REG_GP_O4,
		.global_index = REG_O4,
		.dwarf_number = 12,
		.encoding     = 12,
		.is_virtual   = false,
	},
	{
		.name         = "o5",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_o5,
		.index        = REG_GP_O5,
		.global_index = REG_O5,
		.dwarf_number = 13,
		.encoding     = 13,
		.is_virtual   = false,
	},
	{
		.name         = "sp",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_sp,
		.index        = REG_GP_SP,
		.global_index = REG_SP,
		.dwarf_number = 14,
		.encoding     = 14,
		.is_virtual   = false,
	},
	{
		.name         = "o7",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_o7,
		.index        = REG_GP_O7,
		.global_index = REG_O7,
		.dwarf_number = 15,
		.encoding     = 15,
		.is_virtual   = false,
	},
	{
		.name         = "i0",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_i0,
		.index        = REG_GP_I0,
		.global_index = REG_I0,
		.dwarf_number = 24,
		.encoding     = 24,
		.is_virtual   = false,
	},
	{
		.name         = "i1",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_i1,
		.index        = REG_GP_I1,
		.global_index = REG_I1,
		.dwarf_number = 25,
		.encoding     = 25,
		.is_virtual   = false,
	},
	{
		.name         = "i2",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_i2,
		.index        = REG_GP_I2,
		.global_index = REG_I2,
		.dwarf_number = 26,
		.encoding     = 26,
		.is_virtual   = false,
	},
	{
		.name         = "i3",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_i3,
		.index        = REG_GP_I3,
		.global_index = REG_I3,
		.dwarf_number = 27,
		.encoding     = 27,
		.is_virtual   = false,
	},
	{
		.name         = "i4",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_i4,
		.index        = REG_GP_I4,
		.global_index = REG_I4,
		.dwarf_number = 28,
		.encoding     = 28,
		.is_virtual   = false,
	},
	{
		.name         = "i5",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_i5,
		.index        = REG_GP_I5,
		.global_index = REG_I5,
		.dwarf_number = 29,
		.encoding     = 29,
		.is_virtual   = false,
	},
	{
		.name         = "fp",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_fp,
		.index        = REG_GP_FP,
		.global_index = REG_FP,
		.dwarf_number = 30,
		.encoding     = 30,
		.is_virtual   = false,
	},
	{
		.name         = "i7",
		.cls          = &sparc_reg_classes[CLASS_sparc_gp],
		.single_req   = &sparc_single_reg_req_gp_i7,
		.index        = REG_GP_I7,
		.global_index = REG_I7,
		.dwarf_number = 31,
		.encoding     = 31,
		.is_virtual   = false,
	},
	{
		.name         = "y",
		.cls          = &sparc_reg_classes[CLASS_sparc_mul_div_high_res],
		.single_req   = &sparc_single_reg_req_mul_div_high_res_y,
		.index        = REG_MUL_DIV_HIGH_RES_Y,
		.global_index = REG_Y,
		.dwarf_number = 0,
		.encoding     = REG_MUL_DIV_HIGH_RES_Y,
		.is_virtual   = false,
	},

};

/**
 * Initializes sparc register classes.
 */
void sparc_register_init(void)
{
	sparc_reg_classes[CLASS_sparc_flags].mode = mode_Bu;
	sparc_reg_classes[CLASS_sparc_fp].mode = mode_F;
	sparc_reg_classes[CLASS_sparc_fpflags].mode = mode_Bu;
	sparc_reg_classes[CLASS_sparc_gp].mode = mode_Iu;
	sparc_reg_classes[CLASS_sparc_mul_div_high_res].mode = mode_Iu;

}
