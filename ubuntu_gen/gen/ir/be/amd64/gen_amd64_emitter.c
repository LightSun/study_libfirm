/**
 * @file
 * @brief Generated functions to emit code for assembler ir nodes.
 * @note  DO NOT EDIT THIS FILE, your changes will be lost.
 *         Edit /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/amd64/amd64_spec.pl instead.
 *         created by: /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/scripts/generate_emitter.pl /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/amd64/amd64_spec.pl /home/heaven7/heaven7/temp/build-cparser-Desktop_Qt_5_14_2_GCC_64bit-Debug/libfirm/gen/ir/be/amd64
 * @date  Mon Aug  8 09:46:25 2022
 */
#include "gen_amd64_emitter.h"

#include "beemithlp.h"
#include "gen_amd64_new_nodes.h"
#include "amd64_emitter.h"

static void emit_amd64_add(ir_node const *const node)
{
	amd64_emitf(node, "add%M %AM");
}

static void emit_amd64_adds(ir_node const *const node)
{
	amd64_emitf(node, "adds%MX %AM");
}

static void emit_amd64_and(ir_node const *const node)
{
	amd64_emitf(node, "and%M %AM");
}

static void emit_amd64_bsf(ir_node const *const node)
{
	amd64_emitf(node, "bsf%M %AM, %D0");
}

static void emit_amd64_bsr(ir_node const *const node)
{
	amd64_emitf(node, "bsr%M %AM, %D0");
}

static void emit_amd64_call(ir_node const *const node)
{
	amd64_emitf(node, "call %*AM");
}

static void emit_amd64_cltd(ir_node const *const node)
{
	amd64_emitf(node, "cltd");
}

static void emit_amd64_cmp(ir_node const *const node)
{
	amd64_emitf(node, "cmp%M %AM");
}

static void emit_amd64_cmpxchg(ir_node const *const node)
{
	amd64_emitf(node, "lock cmpxchg%M %AM");
}

static void emit_amd64_cqto(ir_node const *const node)
{
	amd64_emitf(node, "cqto");
}

static void emit_amd64_cvtsd2ss(ir_node const *const node)
{
	amd64_emitf(node, "cvtsd2ss %AM, %^D0");
}

static void emit_amd64_cvtsi2sd(ir_node const *const node)
{
	amd64_emitf(node, "cvtsi2sd %AM, %^D0");
}

static void emit_amd64_cvtsi2ss(ir_node const *const node)
{
	amd64_emitf(node, "cvtsi2ss %AM, %^D0");
}

static void emit_amd64_cvtss2sd(ir_node const *const node)
{
	amd64_emitf(node, "cvtss2sd %AM, %^D0");
}

static void emit_amd64_cvttsd2si(ir_node const *const node)
{
	amd64_emitf(node, "cvttsd2si %AM, %D0");
}

static void emit_amd64_cvttss2si(ir_node const *const node)
{
	amd64_emitf(node, "cvttss2si %AM, %D0");
}

static void emit_amd64_div(ir_node const *const node)
{
	amd64_emitf(node, "div%M %AM");
}

static void emit_amd64_divs(ir_node const *const node)
{
	amd64_emitf(node, "divs%MX %AM");
}

static void emit_amd64_fadd(ir_node const *const node)
{
	amd64_emitf(node, "fadd%FP %AF");
}

static void emit_amd64_fchs(ir_node const *const node)
{
	amd64_emitf(node, "fchs");
}

static void emit_amd64_fdiv(ir_node const *const node)
{
	amd64_emitf(node, "fdiv%FR%FP %AF");
}

static void emit_amd64_fdup(ir_node const *const node)
{
	amd64_emitf(node, "fld %F0");
}

static void emit_amd64_fild(ir_node const *const node)
{
	amd64_emitf(node, "fild%M %AM");
}

static void emit_amd64_fisttp(ir_node const *const node)
{
	amd64_emitf(node, "fisttp%M %AM");
}

static void emit_amd64_fld(ir_node const *const node)
{
	amd64_emitf(node, "fld%FM %AM");
}

static void emit_amd64_fld1(ir_node const *const node)
{
	amd64_emitf(node, "fld1");
}

static void emit_amd64_fldz(ir_node const *const node)
{
	amd64_emitf(node, "fldz");
}

static void emit_amd64_fmul(ir_node const *const node)
{
	amd64_emitf(node, "fmul%FP %AF");
}

static void emit_amd64_fpop(ir_node const *const node)
{
	amd64_emitf(node, "fstp %F0");
}

static void emit_amd64_fst(ir_node const *const node)
{
	amd64_emitf(node, "fst%FP%FM %AM");
}

static void emit_amd64_fstp(ir_node const *const node)
{
	amd64_emitf(node, "fstp%FM %AM");
}

static void emit_amd64_fsub(ir_node const *const node)
{
	amd64_emitf(node, "fsub%FR%FP %AF");
}

static void emit_amd64_fucomi(ir_node const *const node)
{
	amd64_emitf(node, "fucom%FPi %F0");
}

static void emit_amd64_fxch(ir_node const *const node)
{
	amd64_emitf(node, "fxch %F0");
}

static void emit_amd64_haddpd(ir_node const *const node)
{
	amd64_emitf(node, "haddpd %AM");
}

static void emit_amd64_idiv(ir_node const *const node)
{
	amd64_emitf(node, "idiv%M %AM");
}

static void emit_amd64_ijmp(ir_node const *const node)
{
	amd64_emitf(node, "jmp %*AM");
}

static void emit_amd64_imul(ir_node const *const node)
{
	amd64_emitf(node, "imul%M %AM");
}

static void emit_amd64_imul_1op(ir_node const *const node)
{
	amd64_emitf(node, "imul%M %AM");
}

static void emit_amd64_lea(ir_node const *const node)
{
	amd64_emitf(node, "lea%M %A, %D0");
}

static void emit_amd64_leave(ir_node const *const node)
{
	amd64_emitf(node, "leave");
}

static void emit_amd64_mov_imm(ir_node const *const node)
{
	amd64_emitf(node, "mov%M $%C, %D0");
}

static void emit_amd64_mov_store(ir_node const *const node)
{
	amd64_emitf(node, "mov%M %AM");
}

static void emit_amd64_movd(ir_node const *const node)
{
	amd64_emitf(node, "movd %AM, %D0");
}

static void emit_amd64_movd_gp_xmm(ir_node const *const node)
{
	amd64_emitf(node, "movd %S0, %D0");
}

static void emit_amd64_movd_xmm_gp(ir_node const *const node)
{
	amd64_emitf(node, "movd %S0, %D0");
}

static void emit_amd64_movdqa(ir_node const *const node)
{
	amd64_emitf(node, "movdqa %AM, %D0");
}

static void emit_amd64_movdqu(ir_node const *const node)
{
	amd64_emitf(node, "movdqu %AM, %D0");
}

static void emit_amd64_movdqu_store(ir_node const *const node)
{
	amd64_emitf(node, "movdqu %^S0, %A");
}

static void emit_amd64_movs(ir_node const *const node)
{
	amd64_emitf(node, "movs%Mq %AM, %^D0");
}

static void emit_amd64_movs_store_xmm(ir_node const *const node)
{
	amd64_emitf(node, "movs%MX %^S0, %A");
}

static void emit_amd64_movs_xmm(ir_node const *const node)
{
	amd64_emitf(node, "movs%MX %AM, %D0");
}

static void emit_amd64_mul(ir_node const *const node)
{
	amd64_emitf(node, "mul%M %AM");
}

static void emit_amd64_muls(ir_node const *const node)
{
	amd64_emitf(node, "muls%MX %AM");
}

static void emit_amd64_neg(ir_node const *const node)
{
	amd64_emitf(node, "neg%M %AM");
}

static void emit_amd64_not(ir_node const *const node)
{
	amd64_emitf(node, "not%M %AM");
}

static void emit_amd64_or(ir_node const *const node)
{
	amd64_emitf(node, "or%M %AM");
}

static void emit_amd64_pop_am(ir_node const *const node)
{
	amd64_emitf(node, "pop%M %A");
}

static void emit_amd64_punpckldq(ir_node const *const node)
{
	amd64_emitf(node, "punpckldq %AM");
}

static void emit_amd64_push_am(ir_node const *const node)
{
	amd64_emitf(node, "push%M %A");
}

static void emit_amd64_push_reg(ir_node const *const node)
{
	amd64_emitf(node, "push%M %^S2");
}

static void emit_amd64_pxor_0(ir_node const *const node)
{
	amd64_emitf(node, "pxor %^D0, %^D0");
}

static void emit_amd64_ret(ir_node const *const node)
{
	amd64_emitf(node, "ret");
}

static void emit_amd64_sar(ir_node const *const node)
{
	amd64_emitf(node, "sar%M %SO");
}

static void emit_amd64_sbb(ir_node const *const node)
{
	amd64_emitf(node, "sbb%M %AM");
}

static void emit_amd64_setcc(ir_node const *const node)
{
	amd64_emitf(node, "set%P0 %D0");
}

static void emit_amd64_shl(ir_node const *const node)
{
	amd64_emitf(node, "shl%M %SO");
}

static void emit_amd64_shr(ir_node const *const node)
{
	amd64_emitf(node, "shr%M %SO");
}

static void emit_amd64_sub(ir_node const *const node)
{
	amd64_emitf(node, "sub%M %AM");
}

static void emit_amd64_sub_sp(ir_node const *const node)
{
	amd64_emitf(node, "subq %AM\nmovq %%rsp, %D1");
}

static void emit_amd64_subpd(ir_node const *const node)
{
	amd64_emitf(node, "subpd %AM");
}

static void emit_amd64_subs(ir_node const *const node)
{
	amd64_emitf(node, "subs%MX %AM");
}

static void emit_amd64_test(ir_node const *const node)
{
	amd64_emitf(node, "test%M %AM");
}

static void emit_amd64_ucomis(ir_node const *const node)
{
	amd64_emitf(node, "ucomis%MX %AM");
}

static void emit_amd64_xor(ir_node const *const node)
{
	amd64_emitf(node, "xor%M %AM");
}

static void emit_amd64_xor_0(ir_node const *const node)
{
	amd64_emitf(node, "xor%M %3D0, %3D0");
}

static void emit_amd64_xorp(ir_node const *const node)
{
	amd64_emitf(node, "xorp%MX %AM");
}

static void emit_amd64_xorp_0(ir_node const *const node)
{
	amd64_emitf(node, "xorp%MX %^D0, %^D0");
}



void amd64_register_spec_emitters(void)
{
	be_set_emitter(op_amd64_add, emit_amd64_add);
	be_set_emitter(op_amd64_adds, emit_amd64_adds);
	be_set_emitter(op_amd64_and, emit_amd64_and);
	be_set_emitter(op_amd64_bsf, emit_amd64_bsf);
	be_set_emitter(op_amd64_bsr, emit_amd64_bsr);
	be_set_emitter(op_amd64_call, emit_amd64_call);
	be_set_emitter(op_amd64_cltd, emit_amd64_cltd);
	be_set_emitter(op_amd64_cmp, emit_amd64_cmp);
	be_set_emitter(op_amd64_cmpxchg, emit_amd64_cmpxchg);
	be_set_emitter(op_amd64_cqto, emit_amd64_cqto);
	be_set_emitter(op_amd64_cvtsd2ss, emit_amd64_cvtsd2ss);
	be_set_emitter(op_amd64_cvtsi2sd, emit_amd64_cvtsi2sd);
	be_set_emitter(op_amd64_cvtsi2ss, emit_amd64_cvtsi2ss);
	be_set_emitter(op_amd64_cvtss2sd, emit_amd64_cvtss2sd);
	be_set_emitter(op_amd64_cvttsd2si, emit_amd64_cvttsd2si);
	be_set_emitter(op_amd64_cvttss2si, emit_amd64_cvttss2si);
	be_set_emitter(op_amd64_div, emit_amd64_div);
	be_set_emitter(op_amd64_divs, emit_amd64_divs);
	be_set_emitter(op_amd64_fadd, emit_amd64_fadd);
	be_set_emitter(op_amd64_fchs, emit_amd64_fchs);
	be_set_emitter(op_amd64_fdiv, emit_amd64_fdiv);
	be_set_emitter(op_amd64_fdup, emit_amd64_fdup);
	be_set_emitter(op_amd64_fild, emit_amd64_fild);
	be_set_emitter(op_amd64_fisttp, emit_amd64_fisttp);
	be_set_emitter(op_amd64_fld, emit_amd64_fld);
	be_set_emitter(op_amd64_fld1, emit_amd64_fld1);
	be_set_emitter(op_amd64_fldz, emit_amd64_fldz);
	be_set_emitter(op_amd64_fmul, emit_amd64_fmul);
	be_set_emitter(op_amd64_fpop, emit_amd64_fpop);
	be_set_emitter(op_amd64_fst, emit_amd64_fst);
	be_set_emitter(op_amd64_fstp, emit_amd64_fstp);
	be_set_emitter(op_amd64_fsub, emit_amd64_fsub);
	be_set_emitter(op_amd64_fucomi, emit_amd64_fucomi);
	be_set_emitter(op_amd64_fxch, emit_amd64_fxch);
	be_set_emitter(op_amd64_haddpd, emit_amd64_haddpd);
	be_set_emitter(op_amd64_idiv, emit_amd64_idiv);
	be_set_emitter(op_amd64_ijmp, emit_amd64_ijmp);
	be_set_emitter(op_amd64_imul, emit_amd64_imul);
	be_set_emitter(op_amd64_imul_1op, emit_amd64_imul_1op);
	be_set_emitter(op_amd64_lea, emit_amd64_lea);
	be_set_emitter(op_amd64_leave, emit_amd64_leave);
	be_set_emitter(op_amd64_mov_imm, emit_amd64_mov_imm);
	be_set_emitter(op_amd64_mov_store, emit_amd64_mov_store);
	be_set_emitter(op_amd64_movd, emit_amd64_movd);
	be_set_emitter(op_amd64_movd_gp_xmm, emit_amd64_movd_gp_xmm);
	be_set_emitter(op_amd64_movd_xmm_gp, emit_amd64_movd_xmm_gp);
	be_set_emitter(op_amd64_movdqa, emit_amd64_movdqa);
	be_set_emitter(op_amd64_movdqu, emit_amd64_movdqu);
	be_set_emitter(op_amd64_movdqu_store, emit_amd64_movdqu_store);
	be_set_emitter(op_amd64_movs, emit_amd64_movs);
	be_set_emitter(op_amd64_movs_store_xmm, emit_amd64_movs_store_xmm);
	be_set_emitter(op_amd64_movs_xmm, emit_amd64_movs_xmm);
	be_set_emitter(op_amd64_mul, emit_amd64_mul);
	be_set_emitter(op_amd64_muls, emit_amd64_muls);
	be_set_emitter(op_amd64_neg, emit_amd64_neg);
	be_set_emitter(op_amd64_not, emit_amd64_not);
	be_set_emitter(op_amd64_or, emit_amd64_or);
	be_set_emitter(op_amd64_pop_am, emit_amd64_pop_am);
	be_set_emitter(op_amd64_punpckldq, emit_amd64_punpckldq);
	be_set_emitter(op_amd64_push_am, emit_amd64_push_am);
	be_set_emitter(op_amd64_push_reg, emit_amd64_push_reg);
	be_set_emitter(op_amd64_pxor_0, emit_amd64_pxor_0);
	be_set_emitter(op_amd64_ret, emit_amd64_ret);
	be_set_emitter(op_amd64_sar, emit_amd64_sar);
	be_set_emitter(op_amd64_sbb, emit_amd64_sbb);
	be_set_emitter(op_amd64_setcc, emit_amd64_setcc);
	be_set_emitter(op_amd64_shl, emit_amd64_shl);
	be_set_emitter(op_amd64_shr, emit_amd64_shr);
	be_set_emitter(op_amd64_sub, emit_amd64_sub);
	be_set_emitter(op_amd64_sub_sp, emit_amd64_sub_sp);
	be_set_emitter(op_amd64_subpd, emit_amd64_subpd);
	be_set_emitter(op_amd64_subs, emit_amd64_subs);
	be_set_emitter(op_amd64_test, emit_amd64_test);
	be_set_emitter(op_amd64_ucomis, emit_amd64_ucomis);
	be_set_emitter(op_amd64_xor, emit_amd64_xor);
	be_set_emitter(op_amd64_xor_0, emit_amd64_xor_0);
	be_set_emitter(op_amd64_xorp, emit_amd64_xorp);
	be_set_emitter(op_amd64_xorp_0, emit_amd64_xorp_0);

}

void amd64_register_spec_binary_emitters(void)
{

}
