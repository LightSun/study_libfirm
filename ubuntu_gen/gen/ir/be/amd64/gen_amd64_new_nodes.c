#include "gen_amd64_new_nodes.h"

#include "benode.h"
#include "amd64_bearch_t.h"
#include "gen_amd64_regalloc_if.h"
#include "amd64_new_nodes_t.h"
#include "fourcc.h"
#include "irgopt.h"
#include "ircons_t.h"

ir_op *op_amd64_add = NULL;
ir_op *op_amd64_adds = NULL;
ir_op *op_amd64_and = NULL;
ir_op *op_amd64_bsf = NULL;
ir_op *op_amd64_bsr = NULL;
ir_op *op_amd64_call = NULL;
ir_op *op_amd64_cltd = NULL;
ir_op *op_amd64_cmp = NULL;
ir_op *op_amd64_cmpxchg = NULL;
ir_op *op_amd64_copyB = NULL;
ir_op *op_amd64_copyB_i = NULL;
ir_op *op_amd64_cqto = NULL;
ir_op *op_amd64_cvtsd2ss = NULL;
ir_op *op_amd64_cvtsi2sd = NULL;
ir_op *op_amd64_cvtsi2ss = NULL;
ir_op *op_amd64_cvtss2sd = NULL;
ir_op *op_amd64_cvttsd2si = NULL;
ir_op *op_amd64_cvttss2si = NULL;
ir_op *op_amd64_div = NULL;
ir_op *op_amd64_divs = NULL;
ir_op *op_amd64_fadd = NULL;
ir_op *op_amd64_fchs = NULL;
ir_op *op_amd64_fdiv = NULL;
ir_op *op_amd64_fdup = NULL;
ir_op *op_amd64_fild = NULL;
ir_op *op_amd64_fisttp = NULL;
ir_op *op_amd64_fld = NULL;
ir_op *op_amd64_fld1 = NULL;
ir_op *op_amd64_fldz = NULL;
ir_op *op_amd64_fmul = NULL;
ir_op *op_amd64_fpop = NULL;
ir_op *op_amd64_fst = NULL;
ir_op *op_amd64_fstp = NULL;
ir_op *op_amd64_fsub = NULL;
ir_op *op_amd64_fucomi = NULL;
ir_op *op_amd64_fxch = NULL;
ir_op *op_amd64_haddpd = NULL;
ir_op *op_amd64_idiv = NULL;
ir_op *op_amd64_ijmp = NULL;
ir_op *op_amd64_imul = NULL;
ir_op *op_amd64_imul_1op = NULL;
ir_op *op_amd64_jcc = NULL;
ir_op *op_amd64_jmp = NULL;
ir_op *op_amd64_jmp_switch = NULL;
ir_op *op_amd64_l_haddpd = NULL;
ir_op *op_amd64_l_punpckldq = NULL;
ir_op *op_amd64_l_subpd = NULL;
ir_op *op_amd64_lea = NULL;
ir_op *op_amd64_leave = NULL;
ir_op *op_amd64_mov_gp = NULL;
ir_op *op_amd64_mov_imm = NULL;
ir_op *op_amd64_mov_store = NULL;
ir_op *op_amd64_movd = NULL;
ir_op *op_amd64_movd_gp_xmm = NULL;
ir_op *op_amd64_movd_xmm_gp = NULL;
ir_op *op_amd64_movdqa = NULL;
ir_op *op_amd64_movdqu = NULL;
ir_op *op_amd64_movdqu_store = NULL;
ir_op *op_amd64_movs = NULL;
ir_op *op_amd64_movs_store_xmm = NULL;
ir_op *op_amd64_movs_xmm = NULL;
ir_op *op_amd64_mul = NULL;
ir_op *op_amd64_muls = NULL;
ir_op *op_amd64_neg = NULL;
ir_op *op_amd64_not = NULL;
ir_op *op_amd64_or = NULL;
ir_op *op_amd64_pop_am = NULL;
ir_op *op_amd64_punpckldq = NULL;
ir_op *op_amd64_push_am = NULL;
ir_op *op_amd64_push_reg = NULL;
ir_op *op_amd64_pxor_0 = NULL;
ir_op *op_amd64_ret = NULL;
ir_op *op_amd64_sar = NULL;
ir_op *op_amd64_sbb = NULL;
ir_op *op_amd64_setcc = NULL;
ir_op *op_amd64_shl = NULL;
ir_op *op_amd64_shr = NULL;
ir_op *op_amd64_sub = NULL;
ir_op *op_amd64_sub_sp = NULL;
ir_op *op_amd64_subpd = NULL;
ir_op *op_amd64_subs = NULL;
ir_op *op_amd64_test = NULL;
ir_op *op_amd64_ucomis = NULL;
ir_op *op_amd64_xor = NULL;
ir_op *op_amd64_xor_0 = NULL;
ir_op *op_amd64_xorp = NULL;
ir_op *op_amd64_xorp_0 = NULL;


static int amd64_opcode_start = -1;

/** A tag for the amd64 opcodes. */
#define amd64_op_tag FOURCC('a', 'm', 'd', '6')

/** Return 1 if the given opcode is a amd64 machine op, 0 otherwise */
int is_amd64_op(const ir_op *op)
{
	return get_op_tag(op) == amd64_op_tag;
}

/** Return 1 if the given node is a amd64 machine node, 0 otherwise */
int is_amd64_irn(const ir_node *node)
{
	return is_amd64_op(get_irn_op(node));
}

int get_amd64_irn_opcode(const ir_node *node)
{
	assert(is_amd64_irn(node));
	return get_irn_opcode(node) - amd64_opcode_start;
}

#undef BIT
#define BIT(x)  (1 << (x))

static const unsigned amd64_limit_gp_rbp[] = { BIT(REG_GP_RBP), 0 };
static const unsigned amd64_limit_gp_rsp[] = { BIT(REG_GP_RSP), 0 };

static const arch_register_req_t amd64_requirements_gp_rbp_I = {
	.cls               = &amd64_reg_classes[CLASS_amd64_gp],
	.limited           = amd64_limit_gp_rbp,
	.should_be_same    = 0,
	.must_be_different = 0,
	.width             = 1,
	.ignore = true,
};

static const arch_register_req_t amd64_requirements_gp_rsp_I = {
	.cls               = &amd64_reg_classes[CLASS_amd64_gp],
	.limited           = amd64_limit_gp_rsp,
	.should_be_same    = 0,
	.must_be_different = 0,
	.width             = 1,
	.ignore = true,
};

static const arch_register_req_t amd64_requirements_gp_in_r0 = {
	.cls               = &amd64_reg_classes[CLASS_amd64_gp],
	.limited           = NULL,
	.should_be_same    = 1,
	.must_be_different = 0,
	.width             = 1,
};



ir_node *new_bd_amd64_add(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_add, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)amd64_arch_irn_flag_commutative_binop;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_adds(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_adds, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)amd64_arch_irn_flag_commutative_binop;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_and(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_and, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)amd64_arch_irn_flag_commutative_binop;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_bsf(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_bsf, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_bsr(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_bsr, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_call(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, int n_res, const amd64_call_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_call, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_call_addr_attr_t *const attr = (amd64_call_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_cltd(dbg_info *dbgi, ir_node *block, ir_node *val)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_single_reg_req_gp_rax,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_cltd, mode_Lu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_attr_t *const attr = (amd64_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_NONE;
x86_insn_size_t size    = X86_SIZE_32;

	init_amd64_attributes(res, op_mode, size);
	arch_set_additional_pressure(res, &amd64_reg_classes[CLASS_amd64_gp], 1);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_single_reg_req_gp_rdx;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_cmp(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_cmp, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_no_requirement;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_cmpxchg(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_cmpxchg, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_single_reg_req_gp_rax;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_copyB(dbg_info *dbgi, ir_node *block, ir_node *dest, ir_node *source, ir_node *count, ir_node *mem, unsigned size)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_single_reg_req_gp_rdi,
		&amd64_single_reg_req_gp_rsi,
		&amd64_single_reg_req_gp_rcx,
		&arch_memory_requirement,
	};

	/* construct in array */
	ir_node *const in[] = {
		dest,
		source,
		count,
		mem,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_copyB, mode_T, 4, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 4;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_copyb_attr_t *const attr = (amd64_copyb_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_NONE, size);
	init_amd64_copyb_attributes(res, size);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_single_reg_req_gp_rdi;
	out_infos[1].req = &amd64_single_reg_req_gp_rsi;
	out_infos[2].req = &amd64_single_reg_req_gp_rcx;
	out_infos[3].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_copyB_i(dbg_info *dbgi, ir_node *block, ir_node *dest, ir_node *source, ir_node *mem, unsigned size)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_single_reg_req_gp_rdi,
		&amd64_single_reg_req_gp_rsi,
		&arch_memory_requirement,
	};

	/* construct in array */
	ir_node *const in[] = {
		dest,
		source,
		mem,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_copyB_i, mode_T, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_copyb_attr_t *const attr = (amd64_copyb_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_NONE, size);
	init_amd64_copyb_attributes(res, size);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_single_reg_req_gp_rdi;
	out_infos[1].req = &amd64_single_reg_req_gp_rsi;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_cqto(dbg_info *dbgi, ir_node *block, ir_node *val)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_single_reg_req_gp_rax,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_cqto, mode_Lu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_attr_t *const attr = (amd64_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_NONE;
x86_insn_size_t size    = X86_SIZE_64;

	init_amd64_attributes(res, op_mode, size);
	arch_set_additional_pressure(res, &amd64_reg_classes[CLASS_amd64_gp], 1);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_single_reg_req_gp_rdx;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_cvtsd2ss(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_cvtsd2ss, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	x86_insn_size_t size = X86_SIZE_64;

	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_cvtsi2sd(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_cvtsi2sd, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_cvtsi2ss(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_cvtsi2ss, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_cvtss2sd(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_cvtss2sd, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_cvttsd2si(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_cvttsd2si, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_cvttss2si(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_cvttss2si, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_div(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_div, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	int const n_res = 4;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	x86_addr_t addr = { .base_input = 0, .variant = X86_ADDR_REG };
amd64_op_mode_t op_mode = AMD64_OP_REG;

	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_single_reg_req_gp_rax;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;
	out_infos[3].req = &amd64_single_reg_req_gp_rdx;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_divs(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_divs, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fadd(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_x87,
		&amd64_class_reg_req_x87,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fadd, x86_mode_E, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_attr_t *const attr = (amd64_x87_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_X87, X86_SIZE_80);

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_x87;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fchs(dbg_info *dbgi, ir_node *block, ir_node *value)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_x87,
	};

	/* construct in array */
	ir_node *const in[] = {
		value,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fchs, x86_mode_E, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_attr_t *const attr = (amd64_x87_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_X87, X86_SIZE_80);

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_x87;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fdiv(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_x87,
		&amd64_class_reg_req_x87,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fdiv, x86_mode_E, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_attr_t *const attr = (amd64_x87_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_X87, X86_SIZE_80);

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_x87;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fdup(dbg_info *dbgi, ir_node *block, ir_node *val, const arch_register_t *reg)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_x87,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fdup, x86_mode_E, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_attr_t *const attr = (amd64_x87_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_X87, X86_SIZE_80);

	attr->x87.reg = reg;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_x87;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fild(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fild, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_addr_attr_t *const attr = (amd64_x87_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->base.addr = addr;

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_x87;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fisttp(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fisttp, mode_M, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_binop_addr_attr_t *const attr = (amd64_x87_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->base = *attr_init;
	assert(attr_init->base.base.op_mode == AMD64_OP_ADDR_REG);
	attr->base.base.base.op_mode = AMD64_OP_X87_ADDR_REG;

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fld(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fld, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_addr_attr_t *const attr = (amd64_x87_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->base.addr = addr;

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_x87;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fld1(dbg_info *dbgi, ir_node *block)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fld1, x86_mode_E, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_attr_t *const attr = (amd64_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_X87;
x86_insn_size_t size    = X86_SIZE_80;

	init_amd64_attributes(res, op_mode, size);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_x87;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fldz(dbg_info *dbgi, ir_node *block)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fldz, x86_mode_E, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_attr_t *const attr = (amd64_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_X87;
x86_insn_size_t size    = X86_SIZE_80;

	init_amd64_attributes(res, op_mode, size);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_x87;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fmul(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_x87,
		&amd64_class_reg_req_x87,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fmul, x86_mode_E, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_attr_t *const attr = (amd64_x87_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_X87, X86_SIZE_80);

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_x87;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fpop(dbg_info *dbgi, ir_node *block, const arch_register_t *reg)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fpop, mode_ANY, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_attr_t *const attr = (amd64_x87_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_X87, X86_SIZE_80);

	attr->x87.reg = reg;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_no_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fst(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fst, mode_M, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_binop_addr_attr_t *const attr = (amd64_x87_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->base = *attr_init;
	assert(attr_init->base.base.op_mode == AMD64_OP_ADDR_REG);
	attr->base.base.base.op_mode = AMD64_OP_X87_ADDR_REG;

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fstp(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fstp, mode_M, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_binop_addr_attr_t *const attr = (amd64_x87_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->base = *attr_init;
	assert(attr_init->base.base.op_mode == AMD64_OP_ADDR_REG);
	attr->base.base.base.op_mode = AMD64_OP_X87_ADDR_REG;

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fsub(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_x87,
		&amd64_class_reg_req_x87,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fsub, x86_mode_E, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_attr_t *const attr = (amd64_x87_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_X87, X86_SIZE_80);

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_x87;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fucomi(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_x87,
		&amd64_class_reg_req_x87,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fucomi, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_attr_t *const attr = (amd64_x87_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_X87, X86_SIZE_80);

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_fxch(dbg_info *dbgi, ir_node *block, const arch_register_t *reg)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_fxch, mode_ANY, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_x87_attr_t *const attr = (amd64_x87_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_X87, X86_SIZE_80);

	attr->x87.reg = reg;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_no_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_haddpd(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_haddpd, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_idiv(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_idiv, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	int const n_res = 4;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	x86_addr_t addr = { .base_input = 0, .variant = X86_ADDR_REG };
amd64_op_mode_t op_mode = AMD64_OP_REG;

	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_single_reg_req_gp_rax;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;
	out_infos[3].req = &amd64_single_reg_req_gp_rdx;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_ijmp(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_ijmp, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_imul(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_imul, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)amd64_arch_irn_flag_commutative_binop;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_imul_1op(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_imul_1op, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	int const n_res = 4;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_single_reg_req_gp_rax;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;
	out_infos[3].req = &amd64_single_reg_req_gp_rdx;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_jcc(dbg_info *dbgi, ir_node *block, ir_node *flags, x86_condition_code_t cc)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_flags,
	};

	/* construct in array */
	ir_node *const in[] = {
		flags,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_jcc, mode_T, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_cc_attr_t *const attr = (amd64_cc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	x86_insn_size_t size = X86_SIZE_64;
	init_amd64_attributes(res, AMD64_OP_CC, size);
	init_amd64_cc_attributes(res, cc);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;
	out_infos[1].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_jmp(dbg_info *dbgi, ir_node *block)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_jmp, mode_X, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_simple_jump;
	irn_flags |= arch_irn_flag_fallthrough;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_attr_t *const attr = (amd64_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_NONE;
x86_insn_size_t size    = X86_SIZE_64;

	init_amd64_attributes(res, op_mode, size);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_jmp_switch(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, int n_res, amd64_op_mode_t op_mode, x86_insn_size_t size, const x86_addr_t *addr, const ir_switch_table *table, ir_entity *table_entity)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_jmp_switch, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_switch_jmp_attr_t *const attr = (amd64_switch_jmp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->base.addr = *addr;
	be_switch_attr_init(res, &attr->swtch, table, table_entity);

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_l_haddpd(dbg_info *dbgi, ir_node *block, ir_node *arg0, ir_node *arg1)
{

	/* construct in array */
	ir_node *const in[] = {
		arg0,
		arg1,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_l_haddpd, amd64_mode_xmm, 2, in);

	/* init node attributes */

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_l_punpckldq(dbg_info *dbgi, ir_node *block, ir_node *arg0, ir_node *arg1)
{

	/* construct in array */
	ir_node *const in[] = {
		arg0,
		arg1,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_l_punpckldq, amd64_mode_xmm, 2, in);

	/* init node attributes */

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_l_subpd(dbg_info *dbgi, ir_node *block, ir_node *arg0, ir_node *arg1)
{

	/* construct in array */
	ir_node *const in[] = {
		arg0,
		arg1,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_l_subpd, amd64_mode_xmm, 2, in);

	/* init node attributes */

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_lea(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_lea, mode_Lu, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_ADDR;

	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_leave(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_single_reg_req_gp_rbp,
		&arch_memory_requirement,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
		op1,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_leave, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_attr_t *const attr = (amd64_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_NONE;
x86_insn_size_t size    = X86_SIZE_64;

	init_amd64_attributes(res, op_mode, size);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_requirements_gp_rbp_I;
	out_infos[1].req = &arch_memory_requirement;
	out_infos[2].req = &amd64_requirements_gp_rsp_I;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_mov_gp(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_mov_gp, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_mov_imm(dbg_info *dbgi, ir_node *block, x86_insn_size_t size, const amd64_imm64_t *imm)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_mov_imm, mode_Lu, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_movimm_attr_t *const attr = (amd64_movimm_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, AMD64_OP_IMM64, size);
	init_amd64_movimm_attributes(res, imm);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_mov_store(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_mov_store, mode_M, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_movd(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_movd, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	x86_insn_size_t size = X86_SIZE_64;

	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_movd_gp_xmm(dbg_info *dbgi, ir_node *block, ir_node *operand, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		operand,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_movd_gp_xmm, amd64_mode_xmm, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_movd_xmm_gp(dbg_info *dbgi, ir_node *block, ir_node *operand, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_xmm,
	};

	/* construct in array */
	ir_node *const in[] = {
		operand,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_movd_xmm_gp, mode_Lu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_movdqa(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_movdqa, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	x86_insn_size_t size = X86_SIZE_128;

	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_movdqu(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_movdqu, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	x86_insn_size_t size = X86_SIZE_128;

	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_movdqu_store(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_movdqu_store, mode_M, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_movs(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_movs, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_movs_store_xmm(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_movs_store_xmm, mode_M, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_movs_xmm(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_movs_xmm, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_mul(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, amd64_op_mode_t op_mode, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_mul, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	int const n_res = 4;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_single_reg_req_gp_rax;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;
	out_infos[3].req = &amd64_single_reg_req_gp_rdx;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_muls(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_muls, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)amd64_arch_irn_flag_commutative_binop;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_neg(dbg_info *dbgi, ir_node *block, ir_node *val, x86_insn_size_t size)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_neg, mode_T, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_REG;
x86_addr_t addr = { .base_input = 0, .variant = X86_ADDR_REG };
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_requirements_gp_in_r0;
	out_infos[1].req = &amd64_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_not(dbg_info *dbgi, ir_node *block, ir_node *val, x86_insn_size_t size)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_not, mode_T, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_REG;
x86_addr_t addr = { .base_input = 0, .variant = X86_ADDR_REG };
	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_requirements_gp_in_r0;
	out_infos[1].req = &amd64_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_or(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_or, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)amd64_arch_irn_flag_commutative_binop;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_pop_am(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_pop_am, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_ADDR;

	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_requirements_gp_rsp_I;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_punpckldq(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_punpckldq, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_push_am(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, x86_insn_size_t size, x86_addr_t addr)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_push_am, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_addr_attr_t *const attr = (amd64_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_ADDR;

	init_amd64_attributes(res, op_mode, size);
	attr->addr = addr;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_requirements_gp_rsp_I;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_push_reg(dbg_info *dbgi, ir_node *block, ir_node *stack, ir_node *mem, ir_node *val, x86_insn_size_t size)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_single_reg_req_gp_rsp,
		&arch_memory_requirement,
		&amd64_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		stack,
		mem,
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_push_reg, mode_T, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_attr_t *const attr = (amd64_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_NONE;

	init_amd64_attributes(res, op_mode, size);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_requirements_gp_rsp_I;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_pxor_0(dbg_info *dbgi, ir_node *block, x86_insn_size_t size)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_pxor_0, amd64_mode_xmm, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_attr_t *const attr = (amd64_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_NONE;
	init_amd64_attributes(res, op_mode, size);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_ret(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_ret, mode_X, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_attr_t *const attr = (amd64_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_NONE;
x86_insn_size_t size    = X86_SIZE_64;

	init_amd64_attributes(res, op_mode, size);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_sar(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_shift_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_sar, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_shift_attr_t *const attr = (amd64_shift_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_sbb(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_sbb, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_setcc(dbg_info *dbgi, ir_node *block, ir_node *flags, x86_condition_code_t cc)
{
	static arch_register_req_t const *in_reqs[] = {
		&amd64_class_reg_req_flags,
	};

	/* construct in array */
	ir_node *const in[] = {
		flags,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_setcc, mode_Lu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_cc_attr_t *const attr = (amd64_cc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	x86_insn_size_t size = X86_SIZE_8;
	init_amd64_attributes(res, AMD64_OP_CC, size);
	init_amd64_cc_attributes(res, cc);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_shl(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_shift_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_shl, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_shift_attr_t *const attr = (amd64_shift_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_shr(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_shift_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_shr, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_shift_attr_t *const attr = (amd64_shift_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;

	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_sub(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_sub, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_sub_sp(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_sub_sp, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_requirements_gp_rsp_I;
	out_infos[1].req = &amd64_class_reg_req_gp;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_subpd(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_subpd, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_subs(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_subs, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_test(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_test, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_no_requirement;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_ucomis(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_ucomis, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_no_requirement;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_xor(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_xor, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)amd64_arch_irn_flag_commutative_binop;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_xor_0(dbg_info *dbgi, ir_node *block, x86_insn_size_t size)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_xor_0, mode_T, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_modify_flags;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_attr_t *const attr = (amd64_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_NONE;
	init_amd64_attributes(res, op_mode, size);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_gp;
	out_infos[1].req = &amd64_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_xorp(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, const amd64_binop_addr_attr_t *attr_init)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_xorp, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)amd64_arch_irn_flag_commutative_binop;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_binop_addr_attr_t *const attr = (amd64_binop_addr_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	*attr = *attr_init;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;
	out_infos[1].req = &arch_no_requirement;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_amd64_xorp_0(dbg_info *dbgi, ir_node *block, x86_insn_size_t size)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_amd64_xorp_0, amd64_mode_xmm, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	amd64_attr_t *const attr = (amd64_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	amd64_op_mode_t op_mode = AMD64_OP_NONE;
	init_amd64_attributes(res, op_mode, size);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &amd64_class_reg_req_xmm;

	verify_new_node(res);
	return optimize_node(res);
}


/**
 * Creates the amd64 specific Firm machine operations
 * needed for the assembler irgs.
 */
void amd64_create_opcodes(void)
{
	ir_op *op;
	int    cur_opcode = get_next_ir_opcodes(iro_amd64_last);

	amd64_opcode_start = cur_opcode;
	op = new_ir_op(cur_opcode + iro_amd64_add, "amd64_add", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_add = op;
	op = new_ir_op(cur_opcode + iro_amd64_adds, "amd64_adds", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_adds = op;
	op = new_ir_op(cur_opcode + iro_amd64_and, "amd64_and", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_and = op;
	op = new_ir_op(cur_opcode + iro_amd64_bsf, "amd64_bsf", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_bsf = op;
	op = new_ir_op(cur_opcode + iro_amd64_bsr, "amd64_bsr", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_bsr = op;
	op = new_ir_op(cur_opcode + iro_amd64_call, "amd64_call", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_call_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_call_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_call = op;
	op = new_ir_op(cur_opcode + iro_amd64_cltd, "amd64_cltd", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_cltd = op;
	op = new_ir_op(cur_opcode + iro_amd64_cmp, "amd64_cmp", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_cmp = op;
	op = new_ir_op(cur_opcode + iro_amd64_cmpxchg, "amd64_cmpxchg", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_cmpxchg = op;
	op = new_ir_op(cur_opcode + iro_amd64_copyB, "amd64_copyB", op_pin_state_floats, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_copyb_attr_t));
	ir_op_set_memory_index(op, 3);	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_copyb_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_copyB = op;
	op = new_ir_op(cur_opcode + iro_amd64_copyB_i, "amd64_copyB_i", op_pin_state_floats, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_copyb_attr_t));
	ir_op_set_memory_index(op, 2);	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_copyb_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_copyB_i = op;
	op = new_ir_op(cur_opcode + iro_amd64_cqto, "amd64_cqto", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_cqto = op;
	op = new_ir_op(cur_opcode + iro_amd64_cvtsd2ss, "amd64_cvtsd2ss", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_cvtsd2ss = op;
	op = new_ir_op(cur_opcode + iro_amd64_cvtsi2sd, "amd64_cvtsi2sd", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_cvtsi2sd = op;
	op = new_ir_op(cur_opcode + iro_amd64_cvtsi2ss, "amd64_cvtsi2ss", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_cvtsi2ss = op;
	op = new_ir_op(cur_opcode + iro_amd64_cvtss2sd, "amd64_cvtss2sd", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_cvtss2sd = op;
	op = new_ir_op(cur_opcode + iro_amd64_cvttsd2si, "amd64_cvttsd2si", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_cvttsd2si = op;
	op = new_ir_op(cur_opcode + iro_amd64_cvttss2si, "amd64_cvttss2si", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_cvttss2si = op;
	op = new_ir_op(cur_opcode + iro_amd64_div, "amd64_div", op_pin_state_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_div = op;
	op = new_ir_op(cur_opcode + iro_amd64_divs, "amd64_divs", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_divs = op;
	op = new_ir_op(cur_opcode + iro_amd64_fadd, "amd64_fadd", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_x87_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_x87_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fadd = op;
	op = new_ir_op(cur_opcode + iro_amd64_fchs, "amd64_fchs", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_x87_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_x87_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fchs = op;
	op = new_ir_op(cur_opcode + iro_amd64_fdiv, "amd64_fdiv", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_x87_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_x87_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fdiv = op;
	op = new_ir_op(cur_opcode + iro_amd64_fdup, "amd64_fdup", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_x87_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, attrs_equal_false);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fdup = op;
	op = new_ir_op(cur_opcode + iro_amd64_fild, "amd64_fild", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_x87_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_x87_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fild = op;
	op = new_ir_op(cur_opcode + iro_amd64_fisttp, "amd64_fisttp", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_x87_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_x87_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fisttp = op;
	op = new_ir_op(cur_opcode + iro_amd64_fld, "amd64_fld", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_x87_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_x87_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fld = op;
	op = new_ir_op(cur_opcode + iro_amd64_fld1, "amd64_fld1", op_pin_state_floats, irop_flag_constlike, oparity_any, -1, sizeof(amd64_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fld1 = op;
	op = new_ir_op(cur_opcode + iro_amd64_fldz, "amd64_fldz", op_pin_state_floats, irop_flag_constlike, oparity_any, -1, sizeof(amd64_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fldz = op;
	op = new_ir_op(cur_opcode + iro_amd64_fmul, "amd64_fmul", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_x87_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_x87_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fmul = op;
	op = new_ir_op(cur_opcode + iro_amd64_fpop, "amd64_fpop", op_pin_state_floats, irop_flag_keep, oparity_any, -1, sizeof(amd64_x87_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, attrs_equal_false);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fpop = op;
	op = new_ir_op(cur_opcode + iro_amd64_fst, "amd64_fst", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_x87_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_x87_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fst = op;
	op = new_ir_op(cur_opcode + iro_amd64_fstp, "amd64_fstp", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_x87_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_x87_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fstp = op;
	op = new_ir_op(cur_opcode + iro_amd64_fsub, "amd64_fsub", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_x87_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_x87_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fsub = op;
	op = new_ir_op(cur_opcode + iro_amd64_fucomi, "amd64_fucomi", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_x87_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_x87_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fucomi = op;
	op = new_ir_op(cur_opcode + iro_amd64_fxch, "amd64_fxch", op_pin_state_floats, irop_flag_keep, oparity_any, -1, sizeof(amd64_x87_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, attrs_equal_false);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_fxch = op;
	op = new_ir_op(cur_opcode + iro_amd64_haddpd, "amd64_haddpd", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_haddpd = op;
	op = new_ir_op(cur_opcode + iro_amd64_idiv, "amd64_idiv", op_pin_state_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_idiv = op;
	op = new_ir_op(cur_opcode + iro_amd64_ijmp, "amd64_ijmp", op_pin_state_pinned, irop_flag_cfopcode|irop_flag_unknown_jump, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_ijmp = op;
	op = new_ir_op(cur_opcode + iro_amd64_imul, "amd64_imul", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_imul = op;
	op = new_ir_op(cur_opcode + iro_amd64_imul_1op, "amd64_imul_1op", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_imul_1op = op;
	op = new_ir_op(cur_opcode + iro_amd64_jcc, "amd64_jcc", op_pin_state_pinned, irop_flag_cfopcode|irop_flag_forking, oparity_any, -1, sizeof(amd64_cc_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_cc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_jcc = op;
	op = new_ir_op(cur_opcode + iro_amd64_jmp, "amd64_jmp", op_pin_state_pinned, irop_flag_cfopcode, oparity_any, -1, sizeof(amd64_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_jmp = op;
	op = new_ir_op(cur_opcode + iro_amd64_jmp_switch, "amd64_jmp_switch", op_pin_state_pinned, irop_flag_cfopcode|irop_flag_forking, oparity_any, -1, sizeof(amd64_switch_jmp_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_switch_jmp_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_jmp_switch = op;
	op = new_ir_op(cur_opcode + iro_amd64_l_haddpd, "amd64_l_haddpd", op_pin_state_floats, irop_flag_none, oparity_any, -1, 0);
	set_op_dump(op, NULL);
	set_op_tag(op, amd64_op_tag);
	op_amd64_l_haddpd = op;
	op = new_ir_op(cur_opcode + iro_amd64_l_punpckldq, "amd64_l_punpckldq", op_pin_state_floats, irop_flag_none, oparity_any, -1, 0);
	set_op_dump(op, NULL);
	set_op_tag(op, amd64_op_tag);
	op_amd64_l_punpckldq = op;
	op = new_ir_op(cur_opcode + iro_amd64_l_subpd, "amd64_l_subpd", op_pin_state_floats, irop_flag_none, oparity_any, -1, 0);
	set_op_dump(op, NULL);
	set_op_tag(op, amd64_op_tag);
	op_amd64_l_subpd = op;
	op = new_ir_op(cur_opcode + iro_amd64_lea, "amd64_lea", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_lea = op;
	op = new_ir_op(cur_opcode + iro_amd64_leave, "amd64_leave", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_attr_t));
	ir_op_set_memory_index(op, 1);	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_leave = op;
	op = new_ir_op(cur_opcode + iro_amd64_mov_gp, "amd64_mov_gp", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_mov_gp = op;
	op = new_ir_op(cur_opcode + iro_amd64_mov_imm, "amd64_mov_imm", op_pin_state_floats, irop_flag_constlike, oparity_any, -1, sizeof(amd64_movimm_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_movimm_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_mov_imm = op;
	op = new_ir_op(cur_opcode + iro_amd64_mov_store, "amd64_mov_store", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_mov_store = op;
	op = new_ir_op(cur_opcode + iro_amd64_movd, "amd64_movd", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_movd = op;
	op = new_ir_op(cur_opcode + iro_amd64_movd_gp_xmm, "amd64_movd_gp_xmm", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_movd_gp_xmm = op;
	op = new_ir_op(cur_opcode + iro_amd64_movd_xmm_gp, "amd64_movd_xmm_gp", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_movd_xmm_gp = op;
	op = new_ir_op(cur_opcode + iro_amd64_movdqa, "amd64_movdqa", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_movdqa = op;
	op = new_ir_op(cur_opcode + iro_amd64_movdqu, "amd64_movdqu", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_movdqu = op;
	op = new_ir_op(cur_opcode + iro_amd64_movdqu_store, "amd64_movdqu_store", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_movdqu_store = op;
	op = new_ir_op(cur_opcode + iro_amd64_movs, "amd64_movs", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_movs = op;
	op = new_ir_op(cur_opcode + iro_amd64_movs_store_xmm, "amd64_movs_store_xmm", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_movs_store_xmm = op;
	op = new_ir_op(cur_opcode + iro_amd64_movs_xmm, "amd64_movs_xmm", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_movs_xmm = op;
	op = new_ir_op(cur_opcode + iro_amd64_mul, "amd64_mul", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_mul = op;
	op = new_ir_op(cur_opcode + iro_amd64_muls, "amd64_muls", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_muls = op;
	op = new_ir_op(cur_opcode + iro_amd64_neg, "amd64_neg", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_neg = op;
	op = new_ir_op(cur_opcode + iro_amd64_not, "amd64_not", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_not = op;
	op = new_ir_op(cur_opcode + iro_amd64_or, "amd64_or", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_or = op;
	op = new_ir_op(cur_opcode + iro_amd64_pop_am, "amd64_pop_am", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_pop_am = op;
	op = new_ir_op(cur_opcode + iro_amd64_punpckldq, "amd64_punpckldq", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_punpckldq = op;
	op = new_ir_op(cur_opcode + iro_amd64_push_am, "amd64_push_am", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_push_am = op;
	op = new_ir_op(cur_opcode + iro_amd64_push_reg, "amd64_push_reg", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(amd64_attr_t));
	ir_op_set_memory_index(op, 1);	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_push_reg = op;
	op = new_ir_op(cur_opcode + iro_amd64_pxor_0, "amd64_pxor_0", op_pin_state_floats, irop_flag_constlike, oparity_any, -1, sizeof(amd64_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_pxor_0 = op;
	op = new_ir_op(cur_opcode + iro_amd64_ret, "amd64_ret", op_pin_state_pinned, irop_flag_cfopcode, oparity_any, -1, sizeof(amd64_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_ret = op;
	op = new_ir_op(cur_opcode + iro_amd64_sar, "amd64_sar", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_shift_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_shift_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_sar = op;
	op = new_ir_op(cur_opcode + iro_amd64_sbb, "amd64_sbb", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_sbb = op;
	op = new_ir_op(cur_opcode + iro_amd64_setcc, "amd64_setcc", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_cc_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_cc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_setcc = op;
	op = new_ir_op(cur_opcode + iro_amd64_shl, "amd64_shl", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_shift_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_shift_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_shl = op;
	op = new_ir_op(cur_opcode + iro_amd64_shr, "amd64_shr", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(amd64_shift_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_shift_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_shr = op;
	op = new_ir_op(cur_opcode + iro_amd64_sub, "amd64_sub", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_sub = op;
	op = new_ir_op(cur_opcode + iro_amd64_sub_sp, "amd64_sub_sp", op_pin_state_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_sub_sp = op;
	op = new_ir_op(cur_opcode + iro_amd64_subpd, "amd64_subpd", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_subpd = op;
	op = new_ir_op(cur_opcode + iro_amd64_subs, "amd64_subs", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_subs = op;
	op = new_ir_op(cur_opcode + iro_amd64_test, "amd64_test", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_test = op;
	op = new_ir_op(cur_opcode + iro_amd64_ucomis, "amd64_ucomis", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_ucomis = op;
	op = new_ir_op(cur_opcode + iro_amd64_xor, "amd64_xor", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_xor = op;
	op = new_ir_op(cur_opcode + iro_amd64_xor_0, "amd64_xor_0", op_pin_state_floats, irop_flag_constlike, oparity_any, -1, sizeof(amd64_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_xor_0 = op;
	op = new_ir_op(cur_opcode + iro_amd64_xorp, "amd64_xorp", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(amd64_binop_addr_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_binop_addr_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_xorp = op;
	op = new_ir_op(cur_opcode + iro_amd64_xorp_0, "amd64_xorp_0", op_pin_state_floats, irop_flag_constlike, oparity_any, -1, sizeof(amd64_attr_t));
	set_op_dump(op, amd64_dump_node);
	set_op_attrs_equal(op, amd64_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, amd64_op_tag);
	op_amd64_xorp_0 = op;

}

void amd64_free_opcodes(void)
{
	free_ir_op(op_amd64_add); op_amd64_add = NULL;
	free_ir_op(op_amd64_adds); op_amd64_adds = NULL;
	free_ir_op(op_amd64_and); op_amd64_and = NULL;
	free_ir_op(op_amd64_bsf); op_amd64_bsf = NULL;
	free_ir_op(op_amd64_bsr); op_amd64_bsr = NULL;
	free_ir_op(op_amd64_call); op_amd64_call = NULL;
	free_ir_op(op_amd64_cltd); op_amd64_cltd = NULL;
	free_ir_op(op_amd64_cmp); op_amd64_cmp = NULL;
	free_ir_op(op_amd64_cmpxchg); op_amd64_cmpxchg = NULL;
	free_ir_op(op_amd64_copyB); op_amd64_copyB = NULL;
	free_ir_op(op_amd64_copyB_i); op_amd64_copyB_i = NULL;
	free_ir_op(op_amd64_cqto); op_amd64_cqto = NULL;
	free_ir_op(op_amd64_cvtsd2ss); op_amd64_cvtsd2ss = NULL;
	free_ir_op(op_amd64_cvtsi2sd); op_amd64_cvtsi2sd = NULL;
	free_ir_op(op_amd64_cvtsi2ss); op_amd64_cvtsi2ss = NULL;
	free_ir_op(op_amd64_cvtss2sd); op_amd64_cvtss2sd = NULL;
	free_ir_op(op_amd64_cvttsd2si); op_amd64_cvttsd2si = NULL;
	free_ir_op(op_amd64_cvttss2si); op_amd64_cvttss2si = NULL;
	free_ir_op(op_amd64_div); op_amd64_div = NULL;
	free_ir_op(op_amd64_divs); op_amd64_divs = NULL;
	free_ir_op(op_amd64_fadd); op_amd64_fadd = NULL;
	free_ir_op(op_amd64_fchs); op_amd64_fchs = NULL;
	free_ir_op(op_amd64_fdiv); op_amd64_fdiv = NULL;
	free_ir_op(op_amd64_fdup); op_amd64_fdup = NULL;
	free_ir_op(op_amd64_fild); op_amd64_fild = NULL;
	free_ir_op(op_amd64_fisttp); op_amd64_fisttp = NULL;
	free_ir_op(op_amd64_fld); op_amd64_fld = NULL;
	free_ir_op(op_amd64_fld1); op_amd64_fld1 = NULL;
	free_ir_op(op_amd64_fldz); op_amd64_fldz = NULL;
	free_ir_op(op_amd64_fmul); op_amd64_fmul = NULL;
	free_ir_op(op_amd64_fpop); op_amd64_fpop = NULL;
	free_ir_op(op_amd64_fst); op_amd64_fst = NULL;
	free_ir_op(op_amd64_fstp); op_amd64_fstp = NULL;
	free_ir_op(op_amd64_fsub); op_amd64_fsub = NULL;
	free_ir_op(op_amd64_fucomi); op_amd64_fucomi = NULL;
	free_ir_op(op_amd64_fxch); op_amd64_fxch = NULL;
	free_ir_op(op_amd64_haddpd); op_amd64_haddpd = NULL;
	free_ir_op(op_amd64_idiv); op_amd64_idiv = NULL;
	free_ir_op(op_amd64_ijmp); op_amd64_ijmp = NULL;
	free_ir_op(op_amd64_imul); op_amd64_imul = NULL;
	free_ir_op(op_amd64_imul_1op); op_amd64_imul_1op = NULL;
	free_ir_op(op_amd64_jcc); op_amd64_jcc = NULL;
	free_ir_op(op_amd64_jmp); op_amd64_jmp = NULL;
	free_ir_op(op_amd64_jmp_switch); op_amd64_jmp_switch = NULL;
	free_ir_op(op_amd64_l_haddpd); op_amd64_l_haddpd = NULL;
	free_ir_op(op_amd64_l_punpckldq); op_amd64_l_punpckldq = NULL;
	free_ir_op(op_amd64_l_subpd); op_amd64_l_subpd = NULL;
	free_ir_op(op_amd64_lea); op_amd64_lea = NULL;
	free_ir_op(op_amd64_leave); op_amd64_leave = NULL;
	free_ir_op(op_amd64_mov_gp); op_amd64_mov_gp = NULL;
	free_ir_op(op_amd64_mov_imm); op_amd64_mov_imm = NULL;
	free_ir_op(op_amd64_mov_store); op_amd64_mov_store = NULL;
	free_ir_op(op_amd64_movd); op_amd64_movd = NULL;
	free_ir_op(op_amd64_movd_gp_xmm); op_amd64_movd_gp_xmm = NULL;
	free_ir_op(op_amd64_movd_xmm_gp); op_amd64_movd_xmm_gp = NULL;
	free_ir_op(op_amd64_movdqa); op_amd64_movdqa = NULL;
	free_ir_op(op_amd64_movdqu); op_amd64_movdqu = NULL;
	free_ir_op(op_amd64_movdqu_store); op_amd64_movdqu_store = NULL;
	free_ir_op(op_amd64_movs); op_amd64_movs = NULL;
	free_ir_op(op_amd64_movs_store_xmm); op_amd64_movs_store_xmm = NULL;
	free_ir_op(op_amd64_movs_xmm); op_amd64_movs_xmm = NULL;
	free_ir_op(op_amd64_mul); op_amd64_mul = NULL;
	free_ir_op(op_amd64_muls); op_amd64_muls = NULL;
	free_ir_op(op_amd64_neg); op_amd64_neg = NULL;
	free_ir_op(op_amd64_not); op_amd64_not = NULL;
	free_ir_op(op_amd64_or); op_amd64_or = NULL;
	free_ir_op(op_amd64_pop_am); op_amd64_pop_am = NULL;
	free_ir_op(op_amd64_punpckldq); op_amd64_punpckldq = NULL;
	free_ir_op(op_amd64_push_am); op_amd64_push_am = NULL;
	free_ir_op(op_amd64_push_reg); op_amd64_push_reg = NULL;
	free_ir_op(op_amd64_pxor_0); op_amd64_pxor_0 = NULL;
	free_ir_op(op_amd64_ret); op_amd64_ret = NULL;
	free_ir_op(op_amd64_sar); op_amd64_sar = NULL;
	free_ir_op(op_amd64_sbb); op_amd64_sbb = NULL;
	free_ir_op(op_amd64_setcc); op_amd64_setcc = NULL;
	free_ir_op(op_amd64_shl); op_amd64_shl = NULL;
	free_ir_op(op_amd64_shr); op_amd64_shr = NULL;
	free_ir_op(op_amd64_sub); op_amd64_sub = NULL;
	free_ir_op(op_amd64_sub_sp); op_amd64_sub_sp = NULL;
	free_ir_op(op_amd64_subpd); op_amd64_subpd = NULL;
	free_ir_op(op_amd64_subs); op_amd64_subs = NULL;
	free_ir_op(op_amd64_test); op_amd64_test = NULL;
	free_ir_op(op_amd64_ucomis); op_amd64_ucomis = NULL;
	free_ir_op(op_amd64_xor); op_amd64_xor = NULL;
	free_ir_op(op_amd64_xor_0); op_amd64_xor_0 = NULL;
	free_ir_op(op_amd64_xorp); op_amd64_xorp = NULL;
	free_ir_op(op_amd64_xorp_0); op_amd64_xorp_0 = NULL;

}
