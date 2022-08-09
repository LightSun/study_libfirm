#include "gen_mips_new_nodes.h"

#include "benode.h"
#include "mips_bearch_t.h"
#include "gen_mips_regalloc_if.h"
#include "mips_new_nodes_t.h"
#include "fourcc.h"
#include "irgopt.h"
#include "ircons_t.h"

ir_op *op_mips_addiu = NULL;
ir_op *op_mips_addu = NULL;
ir_op *op_mips_and = NULL;
ir_op *op_mips_andi = NULL;
ir_op *op_mips_b = NULL;
ir_op *op_mips_bcc = NULL;
ir_op *op_mips_div_hi = NULL;
ir_op *op_mips_div_lo = NULL;
ir_op *op_mips_divu_hi = NULL;
ir_op *op_mips_divu_lo = NULL;
ir_op *op_mips_ijmp = NULL;
ir_op *op_mips_jal = NULL;
ir_op *op_mips_jalr = NULL;
ir_op *op_mips_lb = NULL;
ir_op *op_mips_lbu = NULL;
ir_op *op_mips_lh = NULL;
ir_op *op_mips_lhu = NULL;
ir_op *op_mips_lui = NULL;
ir_op *op_mips_lw = NULL;
ir_op *op_mips_mult_hi = NULL;
ir_op *op_mips_mult_lo = NULL;
ir_op *op_mips_multu_hi = NULL;
ir_op *op_mips_nor = NULL;
ir_op *op_mips_or = NULL;
ir_op *op_mips_ori = NULL;
ir_op *op_mips_ret = NULL;
ir_op *op_mips_sb = NULL;
ir_op *op_mips_sh = NULL;
ir_op *op_mips_sll = NULL;
ir_op *op_mips_sllv = NULL;
ir_op *op_mips_slt = NULL;
ir_op *op_mips_sltiu = NULL;
ir_op *op_mips_sltu = NULL;
ir_op *op_mips_sra = NULL;
ir_op *op_mips_srav = NULL;
ir_op *op_mips_srl = NULL;
ir_op *op_mips_srlv = NULL;
ir_op *op_mips_subu = NULL;
ir_op *op_mips_sw = NULL;
ir_op *op_mips_switch = NULL;
ir_op *op_mips_xor = NULL;
ir_op *op_mips_xori = NULL;


static int mips_opcode_start = -1;

/** A tag for the mips opcodes. */
#define mips_op_tag FOURCC('m', 'i', 'p', 's')

/** Return 1 if the given opcode is a mips machine op, 0 otherwise */
int is_mips_op(const ir_op *op)
{
	return get_op_tag(op) == mips_op_tag;
}

/** Return 1 if the given node is a mips machine node, 0 otherwise */
int is_mips_irn(const ir_node *node)
{
	return is_mips_op(get_irn_op(node));
}

int get_mips_irn_opcode(const ir_node *node)
{
	assert(is_mips_irn(node));
	return get_irn_opcode(node) - mips_opcode_start;
}

#undef BIT
#define BIT(x)  (1 << (x))




ir_node *new_bd_mips_addiu(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_addiu, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_addu(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_addu, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_and(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_and, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_andi(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_andi, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_b(dbg_info *dbgi, ir_node *block)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_b, mode_X, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_simple_jump;
	irn_flags |= arch_irn_flag_fallthrough;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_bcc(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, mips_cond_t const cond)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_bcc, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_fallthrough;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_cond_attr_t *const attr = (mips_cond_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->cond = cond;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;
	out_infos[1].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_bcc_z(dbg_info *dbgi, ir_node *block, ir_node *left, mips_cond_t const cond)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_bcc, mode_T, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_fallthrough;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_cond_attr_t *const attr = (mips_cond_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->cond = cond;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;
	out_infos[1].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_div_hi(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_div_hi, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_div_lo(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_div_lo, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_divu_hi(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_divu_hi, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_divu_lo(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_divu_lo, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_ijmp(dbg_info *dbgi, ir_node *block, ir_node *op0)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_ijmp, mode_X, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_jal(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, int n_res, ir_entity *const ent, int32_t const val)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_jal, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_jalr(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, int n_res)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_jalr, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_lb(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *base, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		base,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_lb, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;
	out_infos[1].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_lbu(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *base, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		base,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_lbu, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;
	out_infos[1].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_lh(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *base, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		base,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_lh, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;
	out_infos[1].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_lhu(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *base, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		base,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_lhu, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;
	out_infos[1].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_lui(dbg_info *dbgi, ir_node *block, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
	};


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_lui, mode_Iu, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_lw(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *base, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		base,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_lw, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;
	out_infos[1].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_mult_hi(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_mult_hi, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_mult_lo(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_mult_lo, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_multu_hi(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_multu_hi, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_nor(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_nor, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_or(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_or, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_ori(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_ori, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_ret(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_ret, mode_X, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_sb(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *base, ir_node *value, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		base,
		value,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_sb, mode_M, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_sh(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *base, ir_node *value, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		base,
		value,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_sh, mode_M, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_sll(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_sll, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_sllv(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_sllv, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_slt(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_slt, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_sltiu(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_sltiu, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_sltu(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_sltu, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_sra(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_sra, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_srav(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_srav, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_srl(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_srl, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_srlv(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_srlv, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_subu(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_subu, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_sw(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *base, ir_node *value, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		base,
		value,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_sw, mode_M, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_switch(dbg_info *dbgi, ir_node *block, ir_node *op0, int n_res, const ir_switch_table *table, ir_entity *table_entity)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_switch, mode_T, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_switch_attr_t *const attr = (mips_switch_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	be_switch_attr_init(res, &attr->swtch, table, table_entity);

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_xor(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_xor, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_attr_t *const attr = (mips_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_mips_xori(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *const ent, int32_t const val)
{
	static arch_register_req_t const *in_reqs[] = {
		&mips_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_mips_xori, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	mips_immediate_attr_t *const attr = (mips_immediate_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	attr->ent = ent;
	attr->val = val;
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &mips_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}


/**
 * Creates the mips specific Firm machine operations
 * needed for the assembler irgs.
 */
void mips_create_opcodes(void)
{
	ir_op *op;
	int    cur_opcode = get_next_ir_opcodes(iro_mips_last);

	mips_opcode_start = cur_opcode;
	op = new_ir_op(cur_opcode + iro_mips_addiu, "mips_addiu", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_immediate_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_addiu = op;
	op = new_ir_op(cur_opcode + iro_mips_addu, "mips_addu", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_addu = op;
	op = new_ir_op(cur_opcode + iro_mips_and, "mips_and", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_and = op;
	op = new_ir_op(cur_opcode + iro_mips_andi, "mips_andi", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_immediate_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_andi = op;
	op = new_ir_op(cur_opcode + iro_mips_b, "mips_b", op_pin_state_pinned, irop_flag_cfopcode, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_b = op;
	op = new_ir_op(cur_opcode + iro_mips_bcc, "mips_bcc", op_pin_state_pinned, irop_flag_cfopcode|irop_flag_forking, oparity_any, -1, sizeof(mips_cond_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_cond_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_bcc = op;
	op = new_ir_op(cur_opcode + iro_mips_div_hi, "mips_div_hi", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_div_hi = op;
	op = new_ir_op(cur_opcode + iro_mips_div_lo, "mips_div_lo", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_div_lo = op;
	op = new_ir_op(cur_opcode + iro_mips_divu_hi, "mips_divu_hi", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_divu_hi = op;
	op = new_ir_op(cur_opcode + iro_mips_divu_lo, "mips_divu_lo", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_divu_lo = op;
	op = new_ir_op(cur_opcode + iro_mips_ijmp, "mips_ijmp", op_pin_state_pinned, irop_flag_cfopcode|irop_flag_unknown_jump, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_ijmp = op;
	op = new_ir_op(cur_opcode + iro_mips_jal, "mips_jal", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(mips_immediate_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_jal = op;
	op = new_ir_op(cur_opcode + iro_mips_jalr, "mips_jalr", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_jalr = op;
	op = new_ir_op(cur_opcode + iro_mips_lb, "mips_lb", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(mips_immediate_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_lb = op;
	op = new_ir_op(cur_opcode + iro_mips_lbu, "mips_lbu", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(mips_immediate_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_lbu = op;
	op = new_ir_op(cur_opcode + iro_mips_lh, "mips_lh", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(mips_immediate_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_lh = op;
	op = new_ir_op(cur_opcode + iro_mips_lhu, "mips_lhu", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(mips_immediate_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_lhu = op;
	op = new_ir_op(cur_opcode + iro_mips_lui, "mips_lui", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_immediate_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_lui = op;
	op = new_ir_op(cur_opcode + iro_mips_lw, "mips_lw", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(mips_immediate_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_lw = op;
	op = new_ir_op(cur_opcode + iro_mips_mult_hi, "mips_mult_hi", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_mult_hi = op;
	op = new_ir_op(cur_opcode + iro_mips_mult_lo, "mips_mult_lo", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_mult_lo = op;
	op = new_ir_op(cur_opcode + iro_mips_multu_hi, "mips_multu_hi", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_multu_hi = op;
	op = new_ir_op(cur_opcode + iro_mips_nor, "mips_nor", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_nor = op;
	op = new_ir_op(cur_opcode + iro_mips_or, "mips_or", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_or = op;
	op = new_ir_op(cur_opcode + iro_mips_ori, "mips_ori", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_immediate_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_ori = op;
	op = new_ir_op(cur_opcode + iro_mips_ret, "mips_ret", op_pin_state_pinned, irop_flag_cfopcode, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_ret = op;
	op = new_ir_op(cur_opcode + iro_mips_sb, "mips_sb", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(mips_immediate_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_sb = op;
	op = new_ir_op(cur_opcode + iro_mips_sh, "mips_sh", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(mips_immediate_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_sh = op;
	op = new_ir_op(cur_opcode + iro_mips_sll, "mips_sll", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_immediate_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_sll = op;
	op = new_ir_op(cur_opcode + iro_mips_sllv, "mips_sllv", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_sllv = op;
	op = new_ir_op(cur_opcode + iro_mips_slt, "mips_slt", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_slt = op;
	op = new_ir_op(cur_opcode + iro_mips_sltiu, "mips_sltiu", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_immediate_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_sltiu = op;
	op = new_ir_op(cur_opcode + iro_mips_sltu, "mips_sltu", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_sltu = op;
	op = new_ir_op(cur_opcode + iro_mips_sra, "mips_sra", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_immediate_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_sra = op;
	op = new_ir_op(cur_opcode + iro_mips_srav, "mips_srav", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_srav = op;
	op = new_ir_op(cur_opcode + iro_mips_srl, "mips_srl", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_immediate_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_srl = op;
	op = new_ir_op(cur_opcode + iro_mips_srlv, "mips_srlv", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_srlv = op;
	op = new_ir_op(cur_opcode + iro_mips_subu, "mips_subu", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_subu = op;
	op = new_ir_op(cur_opcode + iro_mips_sw, "mips_sw", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(mips_immediate_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_sw = op;
	op = new_ir_op(cur_opcode + iro_mips_switch, "mips_switch", op_pin_state_pinned, irop_flag_cfopcode|irop_flag_forking, oparity_any, -1, sizeof(mips_switch_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_switch_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_switch = op;
	op = new_ir_op(cur_opcode + iro_mips_xor, "mips_xor", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_xor = op;
	op = new_ir_op(cur_opcode + iro_mips_xori, "mips_xori", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(mips_immediate_attr_t));
	set_op_dump(op, mips_dump_node);
	set_op_attrs_equal(op, mips_immediate_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, mips_op_tag);
	op_mips_xori = op;

}

void mips_free_opcodes(void)
{
	free_ir_op(op_mips_addiu); op_mips_addiu = NULL;
	free_ir_op(op_mips_addu); op_mips_addu = NULL;
	free_ir_op(op_mips_and); op_mips_and = NULL;
	free_ir_op(op_mips_andi); op_mips_andi = NULL;
	free_ir_op(op_mips_b); op_mips_b = NULL;
	free_ir_op(op_mips_bcc); op_mips_bcc = NULL;
	free_ir_op(op_mips_div_hi); op_mips_div_hi = NULL;
	free_ir_op(op_mips_div_lo); op_mips_div_lo = NULL;
	free_ir_op(op_mips_divu_hi); op_mips_divu_hi = NULL;
	free_ir_op(op_mips_divu_lo); op_mips_divu_lo = NULL;
	free_ir_op(op_mips_ijmp); op_mips_ijmp = NULL;
	free_ir_op(op_mips_jal); op_mips_jal = NULL;
	free_ir_op(op_mips_jalr); op_mips_jalr = NULL;
	free_ir_op(op_mips_lb); op_mips_lb = NULL;
	free_ir_op(op_mips_lbu); op_mips_lbu = NULL;
	free_ir_op(op_mips_lh); op_mips_lh = NULL;
	free_ir_op(op_mips_lhu); op_mips_lhu = NULL;
	free_ir_op(op_mips_lui); op_mips_lui = NULL;
	free_ir_op(op_mips_lw); op_mips_lw = NULL;
	free_ir_op(op_mips_mult_hi); op_mips_mult_hi = NULL;
	free_ir_op(op_mips_mult_lo); op_mips_mult_lo = NULL;
	free_ir_op(op_mips_multu_hi); op_mips_multu_hi = NULL;
	free_ir_op(op_mips_nor); op_mips_nor = NULL;
	free_ir_op(op_mips_or); op_mips_or = NULL;
	free_ir_op(op_mips_ori); op_mips_ori = NULL;
	free_ir_op(op_mips_ret); op_mips_ret = NULL;
	free_ir_op(op_mips_sb); op_mips_sb = NULL;
	free_ir_op(op_mips_sh); op_mips_sh = NULL;
	free_ir_op(op_mips_sll); op_mips_sll = NULL;
	free_ir_op(op_mips_sllv); op_mips_sllv = NULL;
	free_ir_op(op_mips_slt); op_mips_slt = NULL;
	free_ir_op(op_mips_sltiu); op_mips_sltiu = NULL;
	free_ir_op(op_mips_sltu); op_mips_sltu = NULL;
	free_ir_op(op_mips_sra); op_mips_sra = NULL;
	free_ir_op(op_mips_srav); op_mips_srav = NULL;
	free_ir_op(op_mips_srl); op_mips_srl = NULL;
	free_ir_op(op_mips_srlv); op_mips_srlv = NULL;
	free_ir_op(op_mips_subu); op_mips_subu = NULL;
	free_ir_op(op_mips_sw); op_mips_sw = NULL;
	free_ir_op(op_mips_switch); op_mips_switch = NULL;
	free_ir_op(op_mips_xor); op_mips_xor = NULL;
	free_ir_op(op_mips_xori); op_mips_xori = NULL;

}
