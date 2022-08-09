/**
 * @file
 * @brief Contains additional external requirements defs for external includes.
 * @note   DO NOT EDIT THIS FILE, your changes will be lost.
 *         Edit /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/amd64/amd64_spec.pl instead.
 *         created by: /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/scripts/generate_regalloc_if.pl /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/amd64/amd64_spec.pl /home/heaven7/heaven7/temp/build-cparser-Desktop_Qt_5_14_2_GCC_64bit-Debug/libfirm/gen/ir/be/amd64
 * @date   Mon Aug  8 09:46:25 2022
 */
#ifndef FIRM_BE_AMD64_GEN_AMD64_REGALLOC_IF_H
#define FIRM_BE_AMD64_GEN_AMD64_REGALLOC_IF_H

#include "bearch.h"

/** global register indices for amd64 registers */
enum reg_indices {
	REG_EFLAGS,
	REG_RAX,
	REG_RCX,
	REG_RDX,
	REG_RSI,
	REG_RDI,
	REG_RBX,
	REG_RBP,
	REG_RSP,
	REG_R8,
	REG_R9,
	REG_R10,
	REG_R11,
	REG_R12,
	REG_R13,
	REG_R14,
	REG_R15,
	REG_ST0,
	REG_ST1,
	REG_ST2,
	REG_ST3,
	REG_ST4,
	REG_ST5,
	REG_ST6,
	REG_ST7,
	REG_XMM0,
	REG_XMM1,
	REG_XMM2,
	REG_XMM3,
	REG_XMM4,
	REG_XMM5,
	REG_XMM6,
	REG_XMM7,
	REG_XMM8,
	REG_XMM9,
	REG_XMM10,
	REG_XMM11,
	REG_XMM12,
	REG_XMM13,
	REG_XMM14,
	REG_XMM15,

	N_AMD64_REGISTERS
};

/** local register indices for amd64 registers */
enum {
	REG_FLAGS_EFLAGS,
};

enum {
	REG_GP_RAX,
	REG_GP_RCX,
	REG_GP_RDX,
	REG_GP_RSI,
	REG_GP_RDI,
	REG_GP_RBX,
	REG_GP_RBP,
	REG_GP_RSP,
	REG_GP_R8,
	REG_GP_R9,
	REG_GP_R10,
	REG_GP_R11,
	REG_GP_R12,
	REG_GP_R13,
	REG_GP_R14,
	REG_GP_R15,
};

enum {
	REG_X87_ST0,
	REG_X87_ST1,
	REG_X87_ST2,
	REG_X87_ST3,
	REG_X87_ST4,
	REG_X87_ST5,
	REG_X87_ST6,
	REG_X87_ST7,
};

enum {
	REG_XMM_XMM0,
	REG_XMM_XMM1,
	REG_XMM_XMM2,
	REG_XMM_XMM3,
	REG_XMM_XMM4,
	REG_XMM_XMM5,
	REG_XMM_XMM6,
	REG_XMM_XMM7,
	REG_XMM_XMM8,
	REG_XMM_XMM9,
	REG_XMM_XMM10,
	REG_XMM_XMM11,
	REG_XMM_XMM12,
	REG_XMM_XMM13,
	REG_XMM_XMM14,
	REG_XMM_XMM15,
};


/** number of registers in amd64 register classes. */
enum {
	N_amd64_flags_REGS = 1,
	N_amd64_gp_REGS = 16,
	N_amd64_x87_REGS = 8,
	N_amd64_xmm_REGS = 16,

};

enum {
	CLASS_amd64_flags,
	CLASS_amd64_gp,
	CLASS_amd64_x87,
	CLASS_amd64_xmm,
	N_AMD64_CLASSES = 4
};

extern const arch_register_req_t amd64_class_reg_req_flags;
extern const arch_register_req_t amd64_single_reg_req_flags_eflags;
extern const arch_register_req_t amd64_class_reg_req_gp;
extern const arch_register_req_t amd64_single_reg_req_gp_rax;
extern const arch_register_req_t amd64_single_reg_req_gp_rcx;
extern const arch_register_req_t amd64_single_reg_req_gp_rdx;
extern const arch_register_req_t amd64_single_reg_req_gp_rsi;
extern const arch_register_req_t amd64_single_reg_req_gp_rdi;
extern const arch_register_req_t amd64_single_reg_req_gp_rbx;
extern const arch_register_req_t amd64_single_reg_req_gp_rbp;
extern const arch_register_req_t amd64_single_reg_req_gp_rsp;
extern const arch_register_req_t amd64_single_reg_req_gp_r8;
extern const arch_register_req_t amd64_single_reg_req_gp_r9;
extern const arch_register_req_t amd64_single_reg_req_gp_r10;
extern const arch_register_req_t amd64_single_reg_req_gp_r11;
extern const arch_register_req_t amd64_single_reg_req_gp_r12;
extern const arch_register_req_t amd64_single_reg_req_gp_r13;
extern const arch_register_req_t amd64_single_reg_req_gp_r14;
extern const arch_register_req_t amd64_single_reg_req_gp_r15;
extern const arch_register_req_t amd64_class_reg_req_x87;
extern const arch_register_req_t amd64_single_reg_req_x87_st0;
extern const arch_register_req_t amd64_single_reg_req_x87_st1;
extern const arch_register_req_t amd64_single_reg_req_x87_st2;
extern const arch_register_req_t amd64_single_reg_req_x87_st3;
extern const arch_register_req_t amd64_single_reg_req_x87_st4;
extern const arch_register_req_t amd64_single_reg_req_x87_st5;
extern const arch_register_req_t amd64_single_reg_req_x87_st6;
extern const arch_register_req_t amd64_single_reg_req_x87_st7;
extern const arch_register_req_t amd64_class_reg_req_xmm;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm0;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm1;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm2;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm3;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm4;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm5;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm6;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm7;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm8;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm9;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm10;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm11;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm12;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm13;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm14;
extern const arch_register_req_t amd64_single_reg_req_xmm_xmm15;


extern const arch_register_t amd64_registers[N_AMD64_REGISTERS];

extern arch_register_class_t amd64_reg_classes[N_AMD64_CLASSES];

void amd64_register_init(void);

#endif