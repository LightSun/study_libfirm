/**
 * @file
 * @brief Function prototypes for the new opcode functions.
 * @note  DO NOT EDIT THIS FILE, your changes will be lost.
 *        Edit /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/arm/arm_spec.pl instead.
 *        created by: /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/scripts/generate_new_opcodes.pl /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/arm/arm_spec.pl /home/heaven7/heaven7/temp/build-cparser-Desktop_Qt_5_14_2_GCC_64bit-Debug/libfirm/gen/ir/be/arm
 * @date  Mon Aug  8 09:46:25 2022
 */
#ifndef FIRM_BE_ARM_GEN_ARM_NEW_NODES_H
#define FIRM_BE_ARM_GEN_ARM_NEW_NODES_H

#include "be_types.h"
#include "irnode_t.h"
#include "arm_nodes_attr.h"

typedef enum arm_opcodes {
	iro_arm_AdC,
	iro_arm_AdC_t,
	iro_arm_Add,
	iro_arm_AddS,
	iro_arm_AddS_t,
	iro_arm_Address,
	iro_arm_Adf,
	iro_arm_And,
	iro_arm_B,
	iro_arm_Bcc,
	iro_arm_Bic,
	iro_arm_Bl,
	iro_arm_Clz,
	iro_arm_Cmfe,
	iro_arm_Cmn,
	iro_arm_Cmp,
	iro_arm_Dvf,
	iro_arm_Eor,
	iro_arm_Flt,
	iro_arm_FrameAddr,
	iro_arm_IJmp,
	iro_arm_Ldf,
	iro_arm_Ldr,
	iro_arm_LinkLdrPC,
	iro_arm_LinkMovPC,
	iro_arm_Mla,
	iro_arm_Mls,
	iro_arm_Mov,
	iro_arm_Muf,
	iro_arm_Mul,
	iro_arm_Mvf,
	iro_arm_Mvn,
	iro_arm_OrPl_t,
	iro_arm_Orr,
	iro_arm_OrrPl,
	iro_arm_Pkhbt,
	iro_arm_Pkhtb,
	iro_arm_Return,
	iro_arm_RsC,
	iro_arm_Rsb,
	iro_arm_RsbS,
	iro_arm_SMulL,
	iro_arm_SMulL_t,
	iro_arm_SbC,
	iro_arm_SbC_t,
	iro_arm_Stf,
	iro_arm_Str,
	iro_arm_Sub,
	iro_arm_SubS,
	iro_arm_SubS_t,
	iro_arm_Suf,
	iro_arm_SwitchJmp,
	iro_arm_Tst,
	iro_arm_UMulL,
	iro_arm_UMulL_t,
	iro_arm_fConst,
	iro_arm_last
} arm_opcodes;


int is_arm_irn(const ir_node *node);
int is_arm_op(const ir_op *op);

int get_arm_irn_opcode(const ir_node *node);
void arm_create_opcodes(void);
void arm_free_opcodes(void);

extern ir_op *op_arm_AdC;

static inline bool is_arm_AdC(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_AdC;
}

/**
 * construct AdC node
 */
ir_node *new_bd_arm_AdC_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *flags, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct AdC node
 */
ir_node *new_bd_arm_AdC_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *flags);
/**
 * construct AdC node
 */
ir_node *new_bd_arm_AdC_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *flags, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct AdC node
 */
ir_node *new_bd_arm_AdC_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, ir_node *flags, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_AdC_t;

static inline bool is_arm_AdC_t(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_AdC_t;
}

/**
 * construct AdC_t node
 */
ir_node *new_bd_arm_AdC_t(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *flags, ir_mode *mode);

extern ir_op *op_arm_Add;

static inline bool is_arm_Add(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Add;
}

/**
 * construct Add node
 */
ir_node *new_bd_arm_Add_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct Add node
 */
ir_node *new_bd_arm_Add_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct Add node
 */
ir_node *new_bd_arm_Add_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct Add node
 */
ir_node *new_bd_arm_Add_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_AddS;

static inline bool is_arm_AddS(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_AddS;
}

/**
 * construct AddS node
 */
ir_node *new_bd_arm_AddS_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct AddS node
 */
ir_node *new_bd_arm_AddS_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct AddS node
 */
ir_node *new_bd_arm_AddS_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct AddS node
 */
ir_node *new_bd_arm_AddS_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_AddS_t;

static inline bool is_arm_AddS_t(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_AddS_t;
}

/**
 * construct AddS_t node
 */
ir_node *new_bd_arm_AddS_t(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);

extern ir_op *op_arm_Address;

static inline bool is_arm_Address(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Address;
}

/**
 * construct Address node
 */
ir_node *new_bd_arm_Address(dbg_info *dbgi, ir_node *block, ir_entity *entity, int offset);

extern ir_op *op_arm_Adf;

static inline bool is_arm_Adf(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Adf;
}

/**
 * construct Adf node
 */
ir_node *new_bd_arm_Adf(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1, ir_mode *op_mode);

extern ir_op *op_arm_And;

static inline bool is_arm_And(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_And;
}

/**
 * construct And node
 */
ir_node *new_bd_arm_And_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct And node
 */
ir_node *new_bd_arm_And_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct And node
 */
ir_node *new_bd_arm_And_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct And node
 */
ir_node *new_bd_arm_And_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_B;

static inline bool is_arm_B(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_B;
}

/**
 * construct B node
 */
ir_node *new_bd_arm_B(dbg_info *dbgi, ir_node *block);

extern ir_op *op_arm_Bcc;

static inline bool is_arm_Bcc(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Bcc;
}

/**
 * construct Bcc node
 */
ir_node *new_bd_arm_Bcc(dbg_info *dbgi, ir_node *block, ir_node *flags, ir_relation relation);

extern ir_op *op_arm_Bic;

static inline bool is_arm_Bic(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Bic;
}

/**
 * construct Bic node
 */
ir_node *new_bd_arm_Bic_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct Bic node
 */
ir_node *new_bd_arm_Bic_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct Bic node
 */
ir_node *new_bd_arm_Bic_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct Bic node
 */
ir_node *new_bd_arm_Bic_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_Bl;

static inline bool is_arm_Bl(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Bl;
}

/**
 * construct Bl node
 */
ir_node *new_bd_arm_Bl(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, int n_res, ir_entity *entity, int offset);

extern ir_op *op_arm_Clz;

static inline bool is_arm_Clz(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Clz;
}

/**
 * construct Clz node
 */
ir_node *new_bd_arm_Clz(dbg_info *dbgi, ir_node *block, ir_node *op0);

extern ir_op *op_arm_Cmfe;

static inline bool is_arm_Cmfe(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Cmfe;
}

/**
 * construct Cmfe node
 */
ir_node *new_bd_arm_Cmfe(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1, bool ins_permuted);

extern ir_op *op_arm_Cmn;

static inline bool is_arm_Cmn(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Cmn;
}

/**
 * construct Cmn node
 */
ir_node *new_bd_arm_Cmn_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot, bool ins_permuted, bool is_unsigned);
/**
 * construct Cmn node
 */
ir_node *new_bd_arm_Cmn_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, bool ins_permuted, bool is_unsigned);
/**
 * construct Cmn node
 */
ir_node *new_bd_arm_Cmn_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate, bool ins_permuted, bool is_unsigned);
/**
 * construct Cmn node
 */
ir_node *new_bd_arm_Cmn_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier, bool ins_permuted, bool is_unsigned);

extern ir_op *op_arm_Cmp;

static inline bool is_arm_Cmp(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Cmp;
}

/**
 * construct Cmp node
 */
ir_node *new_bd_arm_Cmp_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot, bool ins_permuted, bool is_unsigned);
/**
 * construct Cmp node
 */
ir_node *new_bd_arm_Cmp_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, bool ins_permuted, bool is_unsigned);
/**
 * construct Cmp node
 */
ir_node *new_bd_arm_Cmp_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate, bool ins_permuted, bool is_unsigned);
/**
 * construct Cmp node
 */
ir_node *new_bd_arm_Cmp_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier, bool ins_permuted, bool is_unsigned);

extern ir_op *op_arm_Dvf;

static inline bool is_arm_Dvf(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Dvf;
}

/**
 * construct Dvf node
 */
ir_node *new_bd_arm_Dvf(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1, ir_mode *op_mode);

extern ir_op *op_arm_Eor;

static inline bool is_arm_Eor(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Eor;
}

/**
 * construct Eor node
 */
ir_node *new_bd_arm_Eor_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct Eor node
 */
ir_node *new_bd_arm_Eor_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct Eor node
 */
ir_node *new_bd_arm_Eor_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct Eor node
 */
ir_node *new_bd_arm_Eor_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_Flt;

static inline bool is_arm_Flt(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Flt;
}

/**
 * construct Flt node
 */
ir_node *new_bd_arm_Flt(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *op_mode);

extern ir_op *op_arm_FrameAddr;

static inline bool is_arm_FrameAddr(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_FrameAddr;
}

/**
 * construct FrameAddr node
 */
ir_node *new_bd_arm_FrameAddr(dbg_info *dbgi, ir_node *block, ir_node *base, ir_entity *entity, int offset);

extern ir_op *op_arm_IJmp;

static inline bool is_arm_IJmp(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_IJmp;
}

/**
 * construct IJmp node
 */
ir_node *new_bd_arm_IJmp(dbg_info *dbgi, ir_node *block, ir_node *target);

extern ir_op *op_arm_Ldf;

static inline bool is_arm_Ldf(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Ldf;
}

/**
 * construct Ldf node
 */
ir_node *new_bd_arm_Ldf(dbg_info *dbgi, ir_node *block, ir_node *ptr, ir_node *mem, ir_mode *ls_mode, ir_entity *entity, int entity_sign, long offset, bool is_frame_entity);

extern ir_op *op_arm_Ldr;

static inline bool is_arm_Ldr(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Ldr;
}

/**
 * construct Ldr node
 */
ir_node *new_bd_arm_Ldr(dbg_info *dbgi, ir_node *block, ir_node *ptr, ir_node *mem, ir_mode *ls_mode, ir_entity *entity, int entity_sign, long offset, bool is_frame_entity);

extern ir_op *op_arm_LinkLdrPC;

static inline bool is_arm_LinkLdrPC(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_LinkLdrPC;
}

/**
 * construct LinkLdrPC node
 */
ir_node *new_bd_arm_LinkLdrPC(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, int n_res, ir_mode *ls_mode, ir_entity *entity, int entity_sign, long offset, bool is_frame_entity);

extern ir_op *op_arm_LinkMovPC;

static inline bool is_arm_LinkMovPC(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_LinkMovPC;
}

/**
 * construct LinkMovPC node
 */
ir_node *new_bd_arm_LinkMovPC(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, int n_res, unsigned shiftop_input, arm_shift_modifier_t shift_modifier, unsigned char immediate_value, unsigned char immediate_rot);

extern ir_op *op_arm_Mla;

static inline bool is_arm_Mla(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Mla;
}

/**
 * construct Mla node
 */
ir_node *new_bd_arm_Mla(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *add);
/**
 * construct Mla node
 */
ir_node *new_bd_arm_Mla_v5(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *add);

extern ir_op *op_arm_Mls;

static inline bool is_arm_Mls(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Mls;
}

/**
 * construct Mls node
 */
ir_node *new_bd_arm_Mls(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *sub);

extern ir_op *op_arm_Mov;

static inline bool is_arm_Mov(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Mov;
}

/**
 * construct Mov node
 */
ir_node *new_bd_arm_Mov_imm(dbg_info *dbgi, ir_node *block, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct Mov node
 */
ir_node *new_bd_arm_Mov_reg(dbg_info *dbgi, ir_node *block, ir_node *Rm);
/**
 * construct Mov node
 */
ir_node *new_bd_arm_Mov_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *Rm, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct Mov node
 */
ir_node *new_bd_arm_Mov_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *Rm, ir_node *Rs, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_Muf;

static inline bool is_arm_Muf(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Muf;
}

/**
 * construct Muf node
 */
ir_node *new_bd_arm_Muf(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1, ir_mode *op_mode);

extern ir_op *op_arm_Mul;

static inline bool is_arm_Mul(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Mul;
}

/**
 * construct Mul node
 */
ir_node *new_bd_arm_Mul(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);
/**
 * construct Mul node
 */
ir_node *new_bd_arm_Mul_v5(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_arm_Mvf;

static inline bool is_arm_Mvf(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Mvf;
}

/**
 * construct Mvf node
 */
ir_node *new_bd_arm_Mvf(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *op_mode);

extern ir_op *op_arm_Mvn;

static inline bool is_arm_Mvn(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Mvn;
}

/**
 * construct Mvn node
 */
ir_node *new_bd_arm_Mvn_imm(dbg_info *dbgi, ir_node *block, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct Mvn node
 */
ir_node *new_bd_arm_Mvn_reg(dbg_info *dbgi, ir_node *block, ir_node *Rm);
/**
 * construct Mvn node
 */
ir_node *new_bd_arm_Mvn_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *Rm, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct Mvn node
 */
ir_node *new_bd_arm_Mvn_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *Rm, ir_node *Rs, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_OrPl_t;

static inline bool is_arm_OrPl_t(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_OrPl_t;
}

/**
 * construct OrPl_t node
 */
ir_node *new_bd_arm_OrPl_t(dbg_info *dbgi, ir_node *block, ir_node *falseval, ir_node *flags, ir_node *left, ir_node *right, ir_mode *mode);

extern ir_op *op_arm_Orr;

static inline bool is_arm_Orr(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Orr;
}

/**
 * construct Orr node
 */
ir_node *new_bd_arm_Orr_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct Orr node
 */
ir_node *new_bd_arm_Orr_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct Orr node
 */
ir_node *new_bd_arm_Orr_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct Orr node
 */
ir_node *new_bd_arm_Orr_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_OrrPl;

static inline bool is_arm_OrrPl(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_OrrPl;
}

/**
 * construct OrrPl node
 */
ir_node *new_bd_arm_OrrPl(dbg_info *dbgi, ir_node *block, ir_node *falseval, ir_node *flags, ir_node *left, ir_node *right);

extern ir_op *op_arm_Pkhbt;

static inline bool is_arm_Pkhbt(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Pkhbt;
}

/**
 * construct Pkhbt node
 */
ir_node *new_bd_arm_Pkhbt_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct Pkhbt node
 */
ir_node *new_bd_arm_Pkhbt_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct Pkhbt node
 */
ir_node *new_bd_arm_Pkhbt_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct Pkhbt node
 */
ir_node *new_bd_arm_Pkhbt_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_Pkhtb;

static inline bool is_arm_Pkhtb(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Pkhtb;
}

/**
 * construct Pkhtb node
 */
ir_node *new_bd_arm_Pkhtb_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct Pkhtb node
 */
ir_node *new_bd_arm_Pkhtb_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct Pkhtb node
 */
ir_node *new_bd_arm_Pkhtb_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct Pkhtb node
 */
ir_node *new_bd_arm_Pkhtb_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_Return;

static inline bool is_arm_Return(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Return;
}

/**
 * construct Return node
 */
ir_node *new_bd_arm_Return(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs);

extern ir_op *op_arm_RsC;

static inline bool is_arm_RsC(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_RsC;
}

/**
 * construct RsC node
 */
ir_node *new_bd_arm_RsC_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *flags, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct RsC node
 */
ir_node *new_bd_arm_RsC_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *flags);
/**
 * construct RsC node
 */
ir_node *new_bd_arm_RsC_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *flags, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct RsC node
 */
ir_node *new_bd_arm_RsC_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, ir_node *flags, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_Rsb;

static inline bool is_arm_Rsb(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Rsb;
}

/**
 * construct Rsb node
 */
ir_node *new_bd_arm_Rsb_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct Rsb node
 */
ir_node *new_bd_arm_Rsb_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct Rsb node
 */
ir_node *new_bd_arm_Rsb_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct Rsb node
 */
ir_node *new_bd_arm_Rsb_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_RsbS;

static inline bool is_arm_RsbS(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_RsbS;
}

/**
 * construct RsbS node
 */
ir_node *new_bd_arm_RsbS_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct RsbS node
 */
ir_node *new_bd_arm_RsbS_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct RsbS node
 */
ir_node *new_bd_arm_RsbS_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct RsbS node
 */
ir_node *new_bd_arm_RsbS_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_SMulL;

static inline bool is_arm_SMulL(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_SMulL;
}

/**
 * construct SMulL node
 */
ir_node *new_bd_arm_SMulL(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_arm_SMulL_t;

static inline bool is_arm_SMulL_t(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_SMulL_t;
}

/**
 * construct SMulL_t node
 */
ir_node *new_bd_arm_SMulL_t(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);

extern ir_op *op_arm_SbC;

static inline bool is_arm_SbC(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_SbC;
}

/**
 * construct SbC node
 */
ir_node *new_bd_arm_SbC_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *flags, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct SbC node
 */
ir_node *new_bd_arm_SbC_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *flags);
/**
 * construct SbC node
 */
ir_node *new_bd_arm_SbC_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *flags, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct SbC node
 */
ir_node *new_bd_arm_SbC_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, ir_node *flags, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_SbC_t;

static inline bool is_arm_SbC_t(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_SbC_t;
}

/**
 * construct SbC_t node
 */
ir_node *new_bd_arm_SbC_t(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *flags, ir_mode *mode);

extern ir_op *op_arm_Stf;

static inline bool is_arm_Stf(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Stf;
}

/**
 * construct Stf node
 */
ir_node *new_bd_arm_Stf(dbg_info *dbgi, ir_node *block, ir_node *ptr, ir_node *val, ir_node *mem, ir_mode *ls_mode, ir_entity *entity, int entity_sign, long offset, bool is_frame_entity);

extern ir_op *op_arm_Str;

static inline bool is_arm_Str(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Str;
}

/**
 * construct Str node
 */
ir_node *new_bd_arm_Str(dbg_info *dbgi, ir_node *block, ir_node *ptr, ir_node *val, ir_node *mem, ir_mode *ls_mode, ir_entity *entity, int entity_sign, long offset, bool is_frame_entity);

extern ir_op *op_arm_Sub;

static inline bool is_arm_Sub(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Sub;
}

/**
 * construct Sub node
 */
ir_node *new_bd_arm_Sub_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct Sub node
 */
ir_node *new_bd_arm_Sub_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct Sub node
 */
ir_node *new_bd_arm_Sub_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct Sub node
 */
ir_node *new_bd_arm_Sub_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_SubS;

static inline bool is_arm_SubS(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_SubS;
}

/**
 * construct SubS node
 */
ir_node *new_bd_arm_SubS_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot);
/**
 * construct SubS node
 */
ir_node *new_bd_arm_SubS_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);
/**
 * construct SubS node
 */
ir_node *new_bd_arm_SubS_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate);
/**
 * construct SubS node
 */
ir_node *new_bd_arm_SubS_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier);

extern ir_op *op_arm_SubS_t;

static inline bool is_arm_SubS_t(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_SubS_t;
}

/**
 * construct SubS_t node
 */
ir_node *new_bd_arm_SubS_t(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);

extern ir_op *op_arm_Suf;

static inline bool is_arm_Suf(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Suf;
}

/**
 * construct Suf node
 */
ir_node *new_bd_arm_Suf(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1, ir_mode *op_mode);

extern ir_op *op_arm_SwitchJmp;

static inline bool is_arm_SwitchJmp(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_SwitchJmp;
}

/**
 * construct SwitchJmp node
 */
ir_node *new_bd_arm_SwitchJmp(dbg_info *dbgi, ir_node *block, ir_node *op0, int n_res, const ir_switch_table *table);

extern ir_op *op_arm_Tst;

static inline bool is_arm_Tst(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_Tst;
}

/**
 * construct Tst node
 */
ir_node *new_bd_arm_Tst_imm(dbg_info *dbgi, ir_node *block, ir_node *left, unsigned char immediate_value, unsigned char immediate_rot, bool ins_permuted, bool is_unsigned);
/**
 * construct Tst node
 */
ir_node *new_bd_arm_Tst_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, bool ins_permuted, bool is_unsigned);
/**
 * construct Tst node
 */
ir_node *new_bd_arm_Tst_reg_shift_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, arm_shift_modifier_t shift_modifier, unsigned shift_immediate, bool ins_permuted, bool is_unsigned);
/**
 * construct Tst node
 */
ir_node *new_bd_arm_Tst_reg_shift_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *shift, arm_shift_modifier_t shift_modifier, bool ins_permuted, bool is_unsigned);

extern ir_op *op_arm_UMulL;

static inline bool is_arm_UMulL(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_UMulL;
}

/**
 * construct UMulL node
 */
ir_node *new_bd_arm_UMulL(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_arm_UMulL_t;

static inline bool is_arm_UMulL_t(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_UMulL_t;
}

/**
 * construct UMulL_t node
 */
ir_node *new_bd_arm_UMulL_t(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right);

extern ir_op *op_arm_fConst;

static inline bool is_arm_fConst(ir_node const *const n)
{
	return get_irn_op(n) == op_arm_fConst;
}

/**
 * construct fConst node
 */
ir_node *new_bd_arm_fConst(dbg_info *dbgi, ir_node *block, ir_tarval *tv);


typedef enum n_arm_AdC_t {
	n_arm_AdC_t_left = 0,
	n_arm_AdC_t_right = 1,
	n_arm_AdC_t_flags = 2,
} n_arm_AdC_t;

typedef enum pn_arm_AddS {
	pn_arm_AddS_res = 0,
	pn_arm_AddS_flags = 1,
} pn_arm_AddS;

typedef enum pn_arm_AddS_t {
	pn_arm_AddS_t_res = 0,
	pn_arm_AddS_t_flags = 1,
} pn_arm_AddS_t;

typedef enum n_arm_AddS_t {
	n_arm_AddS_t_left = 0,
	n_arm_AddS_t_right = 1,
} n_arm_AddS_t;

typedef enum n_arm_Bcc {
	n_arm_Bcc_flags = 0,
} n_arm_Bcc;

typedef enum pn_arm_Bl {
	pn_arm_Bl_M = 0,
	pn_arm_Bl_stack = 1,
	pn_arm_Bl_first_result = 2,
} pn_arm_Bl;

typedef enum pn_arm_Dvf {
	pn_arm_Dvf_res = 0,
	pn_arm_Dvf_M = 1,
} pn_arm_Dvf;

typedef enum n_arm_FrameAddr {
	n_arm_FrameAddr_base = 0,
} n_arm_FrameAddr;

typedef enum pn_arm_IJmp {
	pn_arm_IJmp_jmp = 0,
} pn_arm_IJmp;

typedef enum n_arm_IJmp {
	n_arm_IJmp_target = 0,
} n_arm_IJmp;

typedef enum pn_arm_Ldf {
	pn_arm_Ldf_res = 0,
	pn_arm_Ldf_M = 1,
} pn_arm_Ldf;

typedef enum n_arm_Ldf {
	n_arm_Ldf_ptr = 0,
	n_arm_Ldf_mem = 1,
} n_arm_Ldf;

typedef enum pn_arm_Ldr {
	pn_arm_Ldr_res = 0,
	pn_arm_Ldr_M = 1,
} pn_arm_Ldr;

typedef enum n_arm_Ldr {
	n_arm_Ldr_ptr = 0,
	n_arm_Ldr_mem = 1,
} n_arm_Ldr;

typedef enum n_arm_Mla {
	n_arm_Mla_left = 0,
	n_arm_Mla_right = 1,
	n_arm_Mla_add = 2,
} n_arm_Mla;

typedef enum n_arm_Mls {
	n_arm_Mls_left = 0,
	n_arm_Mls_right = 1,
	n_arm_Mls_sub = 2,
} n_arm_Mls;

typedef enum n_arm_Mov {
	n_arm_Mov_Rm = 0,
	n_arm_Mov_Rs = 1,
} n_arm_Mov;

typedef enum n_arm_OrPl_t {
	n_arm_OrPl_t_falseval = 0,
	n_arm_OrPl_t_flags = 1,
	n_arm_OrPl_t_left = 2,
	n_arm_OrPl_t_right = 3,
} n_arm_OrPl_t;

typedef enum n_arm_OrrPl {
	n_arm_OrrPl_falseval = 0,
	n_arm_OrrPl_flags = 1,
	n_arm_OrrPl_left = 2,
	n_arm_OrrPl_right = 3,
} n_arm_OrrPl;

typedef enum n_arm_Return {
	n_arm_Return_mem = 0,
	n_arm_Return_sp = 1,
	n_arm_Return_first_result = 2,
} n_arm_Return;

typedef enum pn_arm_RsbS {
	pn_arm_RsbS_res = 0,
	pn_arm_RsbS_flags = 1,
} pn_arm_RsbS;

typedef enum pn_arm_SMulL {
	pn_arm_SMulL_low = 0,
	pn_arm_SMulL_high = 1,
} pn_arm_SMulL;

typedef enum pn_arm_SMulL_t {
	pn_arm_SMulL_t_low = 0,
	pn_arm_SMulL_t_high = 1,
} pn_arm_SMulL_t;

typedef enum n_arm_SMulL_t {
	n_arm_SMulL_t_left = 0,
	n_arm_SMulL_t_right = 1,
} n_arm_SMulL_t;

typedef enum n_arm_SbC_t {
	n_arm_SbC_t_left = 0,
	n_arm_SbC_t_right = 1,
	n_arm_SbC_t_flags = 2,
} n_arm_SbC_t;

typedef enum pn_arm_Stf {
	pn_arm_Stf_M = 0,
} pn_arm_Stf;

typedef enum n_arm_Stf {
	n_arm_Stf_ptr = 0,
	n_arm_Stf_val = 1,
	n_arm_Stf_mem = 2,
} n_arm_Stf;

typedef enum pn_arm_Str {
	pn_arm_Str_M = 0,
} pn_arm_Str;

typedef enum n_arm_Str {
	n_arm_Str_ptr = 0,
	n_arm_Str_val = 1,
	n_arm_Str_mem = 2,
} n_arm_Str;

typedef enum pn_arm_SubS {
	pn_arm_SubS_res = 0,
	pn_arm_SubS_flags = 1,
} pn_arm_SubS;

typedef enum pn_arm_SubS_t {
	pn_arm_SubS_t_res = 0,
	pn_arm_SubS_t_flags = 1,
} pn_arm_SubS_t;

typedef enum n_arm_SubS_t {
	n_arm_SubS_t_left = 0,
	n_arm_SubS_t_right = 1,
} n_arm_SubS_t;

typedef enum pn_arm_UMulL {
	pn_arm_UMulL_low = 0,
	pn_arm_UMulL_high = 1,
} pn_arm_UMulL;

typedef enum pn_arm_UMulL_t {
	pn_arm_UMulL_t_low = 0,
	pn_arm_UMulL_t_high = 1,
} pn_arm_UMulL_t;

typedef enum n_arm_UMulL_t {
	n_arm_UMulL_t_left = 0,
	n_arm_UMulL_t_right = 1,
} n_arm_UMulL_t;


#endif
