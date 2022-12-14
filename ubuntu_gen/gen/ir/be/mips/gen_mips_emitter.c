/**
 * @file
 * @brief Generated functions to emit code for assembler ir nodes.
 * @note  DO NOT EDIT THIS FILE, your changes will be lost.
 *         Edit /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/mips/mips_spec.pl instead.
 *         created by: /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/scripts/generate_emitter.pl /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/mips/mips_spec.pl /home/heaven7/heaven7/temp/build-cparser-Desktop_Qt_5_14_2_GCC_64bit-Debug/libfirm/gen/ir/be/mips
 * @date  Mon Aug  8 09:46:25 2022
 */
#include "gen_mips_emitter.h"

#include "beemithlp.h"
#include "gen_mips_new_nodes.h"
#include "mips_emitter.h"

static void emit_mips_addiu(ir_node const *const node)
{
	mips_emitf(node, "addiu	%D0, %S0, %I");
}

static void emit_mips_addu(ir_node const *const node)
{
	mips_emitf(node, "addu	%D0, %S0, %S1");
}

static void emit_mips_and(ir_node const *const node)
{
	mips_emitf(node, "and	%D0, %S0, %S1");
}

static void emit_mips_andi(ir_node const *const node)
{
	mips_emitf(node, "andi	%D0, %S0, %I");
}

static void emit_mips_div_hi(ir_node const *const node)
{
	mips_emitf(node, "div	%S0, %S1\nmfhi	%D0");
}

static void emit_mips_div_lo(ir_node const *const node)
{
	mips_emitf(node, "div	%S0, %S1\nmflo	%D0");
}

static void emit_mips_divu_hi(ir_node const *const node)
{
	mips_emitf(node, "divu	%S0, %S1\nmfhi	%D0");
}

static void emit_mips_divu_lo(ir_node const *const node)
{
	mips_emitf(node, "divu	%S0, %S1\nmflo	%D0");
}

static void emit_mips_ijmp(ir_node const *const node)
{
	mips_emitf(node, "jr	%S0\nnop");
}

static void emit_mips_jal(ir_node const *const node)
{
	mips_emitf(node, "jal	%J\nnop");
}

static void emit_mips_jalr(ir_node const *const node)
{
	mips_emitf(node, "jalr	%S2\nnop");
}

static void emit_mips_lb(ir_node const *const node)
{
	mips_emitf(node, "lb	%D1, %A");
}

static void emit_mips_lbu(ir_node const *const node)
{
	mips_emitf(node, "lbu	%D1, %A");
}

static void emit_mips_lh(ir_node const *const node)
{
	mips_emitf(node, "lh	%D1, %A");
}

static void emit_mips_lhu(ir_node const *const node)
{
	mips_emitf(node, "lhu	%D1, %A");
}

static void emit_mips_lui(ir_node const *const node)
{
	mips_emitf(node, "lui	%D0, %H");
}

static void emit_mips_lw(ir_node const *const node)
{
	mips_emitf(node, "lw	%D1, %A");
}

static void emit_mips_mult_hi(ir_node const *const node)
{
	mips_emitf(node, "mult	%S0, %S1\nmfhi	%D0");
}

static void emit_mips_mult_lo(ir_node const *const node)
{
	mips_emitf(node, "mult	%S0, %S1\nmflo	%D0");
}

static void emit_mips_multu_hi(ir_node const *const node)
{
	mips_emitf(node, "multu	%S0, %S1\nmfhi	%D0");
}

static void emit_mips_nor(ir_node const *const node)
{
	mips_emitf(node, "nor	%D0, %S0, %S1");
}

static void emit_mips_or(ir_node const *const node)
{
	mips_emitf(node, "or	%D0, %S0, %S1");
}

static void emit_mips_ori(ir_node const *const node)
{
	mips_emitf(node, "ori	%D0, %S0, %I");
}

static void emit_mips_ret(ir_node const *const node)
{
	mips_emitf(node, "jr	%S2\nnop");
}

static void emit_mips_sb(ir_node const *const node)
{
	mips_emitf(node, "sb	%S2, %A");
}

static void emit_mips_sh(ir_node const *const node)
{
	mips_emitf(node, "sh	%S2, %A");
}

static void emit_mips_sll(ir_node const *const node)
{
	mips_emitf(node, "sll	%D0, %S0, %I");
}

static void emit_mips_sllv(ir_node const *const node)
{
	mips_emitf(node, "sllv	%D0, %S0, %S1");
}

static void emit_mips_slt(ir_node const *const node)
{
	mips_emitf(node, "slt	%D0, %S0, %S1");
}

static void emit_mips_sltiu(ir_node const *const node)
{
	mips_emitf(node, "sltiu	%D0, %S0, %I");
}

static void emit_mips_sltu(ir_node const *const node)
{
	mips_emitf(node, "sltu	%D0, %S0, %S1");
}

static void emit_mips_sra(ir_node const *const node)
{
	mips_emitf(node, "sra	%D0, %S0, %I");
}

static void emit_mips_srav(ir_node const *const node)
{
	mips_emitf(node, "srav	%D0, %S0, %S1");
}

static void emit_mips_srl(ir_node const *const node)
{
	mips_emitf(node, "srl	%D0, %S0, %I");
}

static void emit_mips_srlv(ir_node const *const node)
{
	mips_emitf(node, "srlv	%D0, %S0, %S1");
}

static void emit_mips_subu(ir_node const *const node)
{
	mips_emitf(node, "subu	%D0, %S0, %S1");
}

static void emit_mips_sw(ir_node const *const node)
{
	mips_emitf(node, "sw	%S2, %A");
}

static void emit_mips_xor(ir_node const *const node)
{
	mips_emitf(node, "xor	%D0, %S0, %S1");
}

static void emit_mips_xori(ir_node const *const node)
{
	mips_emitf(node, "xori	%D0, %S0, %I");
}



void mips_register_spec_emitters(void)
{
	be_set_emitter(op_mips_addiu, emit_mips_addiu);
	be_set_emitter(op_mips_addu, emit_mips_addu);
	be_set_emitter(op_mips_and, emit_mips_and);
	be_set_emitter(op_mips_andi, emit_mips_andi);
	be_set_emitter(op_mips_div_hi, emit_mips_div_hi);
	be_set_emitter(op_mips_div_lo, emit_mips_div_lo);
	be_set_emitter(op_mips_divu_hi, emit_mips_divu_hi);
	be_set_emitter(op_mips_divu_lo, emit_mips_divu_lo);
	be_set_emitter(op_mips_ijmp, emit_mips_ijmp);
	be_set_emitter(op_mips_jal, emit_mips_jal);
	be_set_emitter(op_mips_jalr, emit_mips_jalr);
	be_set_emitter(op_mips_lb, emit_mips_lb);
	be_set_emitter(op_mips_lbu, emit_mips_lbu);
	be_set_emitter(op_mips_lh, emit_mips_lh);
	be_set_emitter(op_mips_lhu, emit_mips_lhu);
	be_set_emitter(op_mips_lui, emit_mips_lui);
	be_set_emitter(op_mips_lw, emit_mips_lw);
	be_set_emitter(op_mips_mult_hi, emit_mips_mult_hi);
	be_set_emitter(op_mips_mult_lo, emit_mips_mult_lo);
	be_set_emitter(op_mips_multu_hi, emit_mips_multu_hi);
	be_set_emitter(op_mips_nor, emit_mips_nor);
	be_set_emitter(op_mips_or, emit_mips_or);
	be_set_emitter(op_mips_ori, emit_mips_ori);
	be_set_emitter(op_mips_ret, emit_mips_ret);
	be_set_emitter(op_mips_sb, emit_mips_sb);
	be_set_emitter(op_mips_sh, emit_mips_sh);
	be_set_emitter(op_mips_sll, emit_mips_sll);
	be_set_emitter(op_mips_sllv, emit_mips_sllv);
	be_set_emitter(op_mips_slt, emit_mips_slt);
	be_set_emitter(op_mips_sltiu, emit_mips_sltiu);
	be_set_emitter(op_mips_sltu, emit_mips_sltu);
	be_set_emitter(op_mips_sra, emit_mips_sra);
	be_set_emitter(op_mips_srav, emit_mips_srav);
	be_set_emitter(op_mips_srl, emit_mips_srl);
	be_set_emitter(op_mips_srlv, emit_mips_srlv);
	be_set_emitter(op_mips_subu, emit_mips_subu);
	be_set_emitter(op_mips_sw, emit_mips_sw);
	be_set_emitter(op_mips_xor, emit_mips_xor);
	be_set_emitter(op_mips_xori, emit_mips_xori);

}

void mips_register_spec_binary_emitters(void)
{

}
