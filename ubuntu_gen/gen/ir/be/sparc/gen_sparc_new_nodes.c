#include "gen_sparc_new_nodes.h"

#include "benode.h"
#include "sparc_bearch_t.h"
#include "gen_sparc_regalloc_if.h"
#include "sparc_new_nodes_t.h"
#include "fourcc.h"
#include "irgopt.h"
#include "ircons_t.h"

ir_op *op_sparc_Add = NULL;
ir_op *op_sparc_AddCC = NULL;
ir_op *op_sparc_AddCC_t = NULL;
ir_op *op_sparc_AddSP = NULL;
ir_op *op_sparc_AddX = NULL;
ir_op *op_sparc_AddX_t = NULL;
ir_op *op_sparc_And = NULL;
ir_op *op_sparc_AndCCZero = NULL;
ir_op *op_sparc_AndN = NULL;
ir_op *op_sparc_AndNCCZero = NULL;
ir_op *op_sparc_Ba = NULL;
ir_op *op_sparc_Bicc = NULL;
ir_op *op_sparc_Call = NULL;
ir_op *op_sparc_Cas = NULL;
ir_op *op_sparc_Cmp = NULL;
ir_op *op_sparc_FrameAddr = NULL;
ir_op *op_sparc_IJmp = NULL;
ir_op *op_sparc_Ld = NULL;
ir_op *op_sparc_Ldf = NULL;
ir_op *op_sparc_Or = NULL;
ir_op *op_sparc_OrCCZero = NULL;
ir_op *op_sparc_OrN = NULL;
ir_op *op_sparc_OrNCCZero = NULL;
ir_op *op_sparc_Restore = NULL;
ir_op *op_sparc_RestoreZero = NULL;
ir_op *op_sparc_Return = NULL;
ir_op *op_sparc_SDiv = NULL;
ir_op *op_sparc_SMul = NULL;
ir_op *op_sparc_SMulCCZero = NULL;
ir_op *op_sparc_SMulh = NULL;
ir_op *op_sparc_Save = NULL;
ir_op *op_sparc_SetHi = NULL;
ir_op *op_sparc_Sll = NULL;
ir_op *op_sparc_Sra = NULL;
ir_op *op_sparc_Srl = NULL;
ir_op *op_sparc_St = NULL;
ir_op *op_sparc_Stbar = NULL;
ir_op *op_sparc_Stf = NULL;
ir_op *op_sparc_Sub = NULL;
ir_op *op_sparc_SubCC = NULL;
ir_op *op_sparc_SubCC_t = NULL;
ir_op *op_sparc_SubSP = NULL;
ir_op *op_sparc_SubX = NULL;
ir_op *op_sparc_SubX_t = NULL;
ir_op *op_sparc_SwitchJmp = NULL;
ir_op *op_sparc_UDiv = NULL;
ir_op *op_sparc_UMulh = NULL;
ir_op *op_sparc_XNor = NULL;
ir_op *op_sparc_XNorCCZero = NULL;
ir_op *op_sparc_Xor = NULL;
ir_op *op_sparc_XorCCZero = NULL;
ir_op *op_sparc_fabs = NULL;
ir_op *op_sparc_fadd = NULL;
ir_op *op_sparc_fbfcc = NULL;
ir_op *op_sparc_fcmp = NULL;
ir_op *op_sparc_fdiv = NULL;
ir_op *op_sparc_fftof = NULL;
ir_op *op_sparc_fftoi = NULL;
ir_op *op_sparc_fitof = NULL;
ir_op *op_sparc_fmul = NULL;
ir_op *op_sparc_fneg = NULL;
ir_op *op_sparc_fsub = NULL;


static int sparc_opcode_start = -1;

/** A tag for the sparc opcodes. */
#define sparc_op_tag FOURCC('s', 'p', 'a', 'r')

/** Return 1 if the given opcode is a sparc machine op, 0 otherwise */
int is_sparc_op(const ir_op *op)
{
	return get_op_tag(op) == sparc_op_tag;
}

/** Return 1 if the given node is a sparc machine node, 0 otherwise */
int is_sparc_irn(const ir_node *node)
{
	return is_sparc_op(get_irn_op(node));
}

int get_sparc_irn_opcode(const ir_node *node)
{
	assert(is_sparc_irn(node));
	return get_irn_opcode(node) - sparc_opcode_start;
}

#undef BIT
#define BIT(x)  (1 << (x))

static const unsigned sparc_limit_gp_sp[] = { BIT(REG_GP_SP), 0 };

static const arch_register_req_t sparc_requirements_gp_sp_I = {
	.cls               = &sparc_reg_classes[CLASS_sparc_gp],
	.limited           = sparc_limit_gp_sp,
	.should_be_same    = 0,
	.must_be_different = 0,
	.width             = 1,
	.ignore = true,
};

static const arch_register_req_t sparc_requirements_gp_in_r2_not_in_r0_not_in_r1 = {
	.cls               = &sparc_reg_classes[CLASS_sparc_gp],
	.limited           = NULL,
	.should_be_same    = 4,
	.must_be_different = 3,
	.width             = 1,
};

static const arch_register_req_t sparc_requirements_fp_fp_2 = {
	.cls   = &sparc_reg_classes[CLASS_sparc_fp],
	.width = 2,
};

static const arch_register_req_t sparc_requirements_fp_fp_4 = {
	.cls   = &sparc_reg_classes[CLASS_sparc_fp],
	.width = 4,
};



ir_node *new_bd_sparc_Add_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Add, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Add_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Add, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AddCC_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AddCC, mode_T, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;
	out_infos[1].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AddCC_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AddCC, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;
	out_infos[1].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AddCC_t(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AddCC_t, mode_T, 2, in);

	/* init node attributes */

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AddSP(dbg_info *dbgi, ir_node *block, ir_node *stack, ir_node *size)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_single_reg_req_gp_sp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		stack,
		size,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AddSP, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_gp_sp_I;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AddX_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *carry, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_flags,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		carry,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AddX, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AddX_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *carry)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_flags,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
		carry,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AddX, mode_Iu, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AddX_t(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *flags_input, ir_mode *mode)
{

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
		flags_input,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AddX_t, mode, 3, in);

	/* init node attributes */

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_And_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_And, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_And_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_And, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AndCCZero_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AndCCZero, mode_Bu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AndCCZero_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AndCCZero, mode_Bu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AndN_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AndN, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AndN_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AndN, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AndNCCZero_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AndNCCZero, mode_Bu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_AndNCCZero_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_AndNCCZero, mode_Bu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Ba(dbg_info *dbgi, ir_node *block)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Ba, mode_X, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_simple_jump;
	irn_flags |= arch_irn_flag_fallthrough;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Bicc(dbg_info *dbgi, ir_node *block, ir_node *flags, ir_relation relation, bool is_unsigned)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_flags,
	};

	/* construct in array */
	ir_node *const in[] = {
		flags,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Bicc, mode_T, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_fallthrough;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_jmp_cond_attr_t *const attr = (sparc_jmp_cond_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_jmp_cond_attr(res, relation, is_unsigned);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;
	out_infos[1].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Call_imm(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, int n_res, ir_entity *entity, int32_t offset, bool aggregate_return)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Call, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	if (aggregate_return) arch_add_irn_flags(res, (arch_irn_flags_t)sparc_arch_irn_flag_aggregate_return);
		sparc_set_attr_imm(res, entity, offset);

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Call_reg(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, int n_res, bool aggregate_return)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Call, mode_T, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	if (aggregate_return) arch_add_irn_flags(res, (arch_irn_flags_t)sparc_arch_irn_flag_aggregate_return);

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Cas(dbg_info *dbgi, ir_node *block, ir_node *ptr, ir_node *old, ir_node *new, ir_node *mem)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
		&arch_memory_requirement,
	};

	/* construct in array */
	ir_node *const in[] = {
		ptr,
		old,
		new,
		mem,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Cas, mode_T, 4, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_gp_in_r2_not_in_r0_not_in_r1;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Cmp_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Cmp, mode_Bu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Cmp_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Cmp, mode_Bu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_FrameAddr(dbg_info *dbgi, ir_node *block, ir_node *base, ir_entity *entity, int32_t offset)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		base,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_FrameAddr, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, entity, offset);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_IJmp_imm(dbg_info *dbgi, ir_node *block, ir_node *ptr, ir_entity *entity, int32_t offset, bool is_frame_entity)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		ptr,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_IJmp, mode_X, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, NULL, entity, offset, is_frame_entity, false);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_IJmp_reg(dbg_info *dbgi, ir_node *block, ir_node *ptr, ir_node *ptr2)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		ptr,
		ptr2,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_IJmp, mode_X, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, NULL, NULL, 0, false, true);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Ld_imm(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *ptr, ir_mode *ls_mode, ir_entity *entity, int32_t offset, bool is_frame_entity)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		ptr,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Ld, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, ls_mode, entity, offset, is_frame_entity, false);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Ld_reg(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *ptr, ir_node *ptr2, ir_mode *ls_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		ptr,
		ptr2,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Ld, mode_T, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, ls_mode, NULL, 0, false, true);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Ldf_d(dbg_info *dbgi, ir_node *block, ir_node *ptr, ir_node *mem, ir_mode *ls_mode, ir_entity *entity, int32_t offset, bool is_frame_entity)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&arch_memory_requirement,
	};

	/* construct in array */
	ir_node *const in[] = {
		ptr,
		mem,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Ldf, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, ls_mode, entity, offset, is_frame_entity, false);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_2;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Ldf_q(dbg_info *dbgi, ir_node *block, ir_node *ptr, ir_node *mem, ir_mode *ls_mode, ir_entity *entity, int32_t offset, bool is_frame_entity)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&arch_memory_requirement,
	};

	/* construct in array */
	ir_node *const in[] = {
		ptr,
		mem,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Ldf, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, ls_mode, entity, offset, is_frame_entity, false);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_4;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Ldf_s(dbg_info *dbgi, ir_node *block, ir_node *ptr, ir_node *mem, ir_mode *ls_mode, ir_entity *entity, int32_t offset, bool is_frame_entity)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&arch_memory_requirement,
	};

	/* construct in array */
	ir_node *const in[] = {
		ptr,
		mem,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Ldf, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, ls_mode, entity, offset, is_frame_entity, false);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Or_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Or, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Or_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Or, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_OrCCZero_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_OrCCZero, mode_Bu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_OrCCZero_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_OrCCZero, mode_Bu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_OrN_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_OrN, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_OrN_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_OrN, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_OrNCCZero_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_OrNCCZero, mode_Bu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_OrNCCZero_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_OrNCCZero, mode_Bu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Restore_imm(dbg_info *dbgi, ir_node *block, ir_node *stack, ir_node *frame_pointer, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_single_reg_req_gp_sp,
		&sparc_single_reg_req_gp_fp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		stack,
		frame_pointer,
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Restore, mode_T, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_gp_sp_I;
	out_infos[1].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Restore_reg(dbg_info *dbgi, ir_node *block, ir_node *stack, ir_node *frame_pointer, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_single_reg_req_gp_sp,
		&sparc_single_reg_req_gp_fp,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		stack,
		frame_pointer,
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Restore, mode_T, 4, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_gp_sp_I;
	out_infos[1].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_RestoreZero(dbg_info *dbgi, ir_node *block, ir_node *stack, ir_node *frame_pointer)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_single_reg_req_gp_sp,
		&sparc_single_reg_req_gp_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		stack,
		frame_pointer,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_RestoreZero, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_gp_sp_I;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Return_imm(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs, ir_entity *entity, int32_t offset)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Return, mode_X, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
		sparc_set_attr_imm(res, entity, offset);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Return_reg(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs)
{


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Return, mode_X, arity, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SDiv_imm(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *dividend_high, ir_node *dividend_low, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		dividend_high,
		dividend_low,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SDiv, mode_T, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SDiv_reg(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *dividend_high, ir_node *dividend_low, ir_node *divisor)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		dividend_high,
		dividend_low,
		divisor,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SDiv, mode_T, 4, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SMul_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SMul, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SMul_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SMul, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SMulCCZero_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SMulCCZero, mode_Bu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SMulCCZero_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SMulCCZero, mode_Bu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SMulh_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SMulh, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SMulh_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SMulh, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Save_imm(dbg_info *dbgi, ir_node *block, ir_node *stack, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_single_reg_req_gp_sp,
	};

	/* construct in array */
	ir_node *const in[] = {
		stack,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Save, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_schedule_first;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_gp_sp_I;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Save_reg(dbg_info *dbgi, ir_node *block, ir_node *stack, ir_node *increment)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_single_reg_req_gp_sp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		stack,
		increment,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Save, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_schedule_first;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_gp_sp_I;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SetHi(dbg_info *dbgi, ir_node *block, ir_entity *entity, int32_t immediate_value)
{
	arch_register_req_t const **const in_reqs = NULL;


	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SetHi, mode_Iu, 0, NULL);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Sll_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Sll, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Sll_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Sll, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Sra_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Sra, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Sra_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Sra, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Srl_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Srl, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Srl_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Srl, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_St_imm(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *val, ir_node *ptr, ir_mode *ls_mode, ir_entity *entity, int32_t offset, bool is_frame_entity)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		val,
		ptr,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_St, mode_M, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, ls_mode, entity, offset, is_frame_entity, false);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_St_reg(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *val, ir_node *ptr, ir_node *ptr2, ir_mode *ls_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		val,
		ptr,
		ptr2,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_St, mode_M, 4, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, ls_mode, NULL, 0, false, true);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Stbar(dbg_info *dbgi, ir_node *block, ir_node *mem)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Stbar, mode_M, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Stf_d(dbg_info *dbgi, ir_node *block, ir_node *val, ir_node *ptr, ir_node *mem, ir_mode *ls_mode, ir_entity *entity, int32_t offset, bool is_frame_entity)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_2,
		&sparc_class_reg_req_gp,
		&arch_memory_requirement,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
		ptr,
		mem,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Stf, mode_M, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, ls_mode, entity, offset, is_frame_entity, false);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Stf_q(dbg_info *dbgi, ir_node *block, ir_node *val, ir_node *ptr, ir_node *mem, ir_mode *ls_mode, ir_entity *entity, int32_t offset, bool is_frame_entity)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_4,
		&sparc_class_reg_req_gp,
		&arch_memory_requirement,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
		ptr,
		mem,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Stf, mode_M, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, ls_mode, entity, offset, is_frame_entity, false);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Stf_s(dbg_info *dbgi, ir_node *block, ir_node *val, ir_node *ptr, ir_node *mem, ir_mode *ls_mode, ir_entity *entity, int32_t offset, bool is_frame_entity)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
		&sparc_class_reg_req_gp,
		&arch_memory_requirement,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
		ptr,
		mem,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Stf, mode_M, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_load_store_attr_t *const attr = (sparc_load_store_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_load_store_attributes(res, ls_mode, entity, offset, is_frame_entity, false);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Sub_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Sub, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Sub_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Sub, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SubCC_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SubCC, mode_T, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;
	out_infos[1].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SubCC_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SubCC, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;
	out_infos[1].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SubCC_t(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SubCC_t, mode_T, 2, in);

	/* init node attributes */

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SubSP_imm(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *stack, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&sparc_single_reg_req_gp_sp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		stack,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SubSP, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_gp_sp_I;
	out_infos[1].req = &sparc_class_reg_req_gp;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SubSP_reg(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *stack, ir_node *size)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&sparc_single_reg_req_gp_sp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		stack,
		size,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SubSP, mode_T, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 3;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_gp_sp_I;
	out_infos[1].req = &sparc_class_reg_req_gp;
	out_infos[2].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SubX_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *carry, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_flags,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		carry,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SubX, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SubX_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *carry)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_flags,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
		carry,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SubX, mode_Iu, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SubX_t(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_node *flags_input, ir_mode *mode)
{

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
		flags_input,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SubX_t, mode, 3, in);

	/* init node attributes */

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_SwitchJmp(dbg_info *dbgi, ir_node *block, ir_node *op0, int n_res, const ir_switch_table *table, ir_entity *jump_table)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_SwitchJmp, mode_T, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_switch_jmp_attr_t *const attr = (sparc_switch_jmp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	be_switch_attr_init(res, &attr->swtch, table, jump_table);

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_UDiv_imm(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *dividend_high, ir_node *dividend_low, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		dividend_high,
		dividend_low,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_UDiv, mode_T, 3, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_UDiv_reg(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *dividend_high, ir_node *dividend_low, ir_node *divisor)
{
	static arch_register_req_t const *in_reqs[] = {
		&arch_memory_requirement,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		mem,
		dividend_high,
		dividend_low,
		divisor,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_UDiv, mode_T, 4, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_UMulh_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_UMulh, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_UMulh_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_UMulh, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_XNor_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_XNor, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_XNor_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_XNor, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_XNorCCZero_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_XNorCCZero, mode_Bu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_XNorCCZero_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_XNorCCZero, mode_Bu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Xor_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Xor, mode_Iu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_Xor_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_Xor, mode_Iu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_gp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_XorCCZero_imm(dbg_info *dbgi, ir_node *block, ir_node *left, ir_entity *immediate_entity, int32_t immediate_value)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_XorCCZero, mode_Bu, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	sparc_set_attr_imm(res, immediate_entity, immediate_value);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_XorCCZero_reg(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_gp,
		&sparc_class_reg_req_gp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_XorCCZero, mode_Bu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_attr_t *const attr = (sparc_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_flags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fabs_d(dbg_info *dbgi, ir_node *block, ir_node *val, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_2,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fabs, mode_D, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_2;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fabs_q(dbg_info *dbgi, ir_node *block, ir_node *val, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_4,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fabs, sparc_mode_Q, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_4;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fabs_s(dbg_info *dbgi, ir_node *block, ir_node *val, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fabs, mode_F, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fadd_d(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_2,
		&sparc_requirements_fp_fp_2,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fadd, mode_D, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_2;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fadd_q(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_4,
		&sparc_requirements_fp_fp_4,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fadd, sparc_mode_Q, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_4;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fadd_s(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fadd, mode_F, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fbfcc(dbg_info *dbgi, ir_node *block, ir_node *flags, ir_relation relation)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fpflags,
	};

	/* construct in array */
	ir_node *const in[] = {
		flags,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fbfcc, mode_T, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_fallthrough;
	irn_flags |= (arch_irn_flags_t)sparc_arch_irn_flag_has_delay_slot;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_jmp_cond_attr_t *const attr = (sparc_jmp_cond_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	bool const is_unsigned = false;
	init_sparc_jmp_cond_attr(res, relation, is_unsigned);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &arch_exec_requirement;
	out_infos[1].req = &arch_exec_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fcmp_d(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_2,
		&sparc_requirements_fp_fp_2,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
		op1,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fcmp, mode_Bu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fpflags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fcmp_q(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_4,
		&sparc_requirements_fp_fp_4,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
		op1,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fcmp, mode_Bu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fpflags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fcmp_s(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
		op1,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fcmp, mode_Bu, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fpflags;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fdiv_d(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_2,
		&sparc_requirements_fp_fp_2,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fdiv, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_2;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fdiv_q(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_4,
		&sparc_requirements_fp_fp_4,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fdiv, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_4;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fdiv_s(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fdiv, mode_T, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 2;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;
	out_infos[1].req = &arch_memory_requirement;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fftof_d_q(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *src_mode, ir_mode *dest_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_2,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fftof, sparc_mode_Q, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_conv_attr_t *const attr = (sparc_fp_conv_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_conv_attributes(res, src_mode, dest_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_4;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fftof_d_s(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *src_mode, ir_mode *dest_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_2,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fftof, mode_F, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_conv_attr_t *const attr = (sparc_fp_conv_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_conv_attributes(res, src_mode, dest_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fftof_q_d(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *src_mode, ir_mode *dest_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_4,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fftof, mode_D, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_conv_attr_t *const attr = (sparc_fp_conv_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_conv_attributes(res, src_mode, dest_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_2;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fftof_q_s(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *src_mode, ir_mode *dest_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_4,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fftof, mode_F, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_conv_attr_t *const attr = (sparc_fp_conv_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_conv_attributes(res, src_mode, dest_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fftof_s_d(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *src_mode, ir_mode *dest_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fftof, mode_D, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_conv_attr_t *const attr = (sparc_fp_conv_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_conv_attributes(res, src_mode, dest_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_2;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fftof_s_q(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *src_mode, ir_mode *dest_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fftof, sparc_mode_Q, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_conv_attr_t *const attr = (sparc_fp_conv_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_conv_attributes(res, src_mode, dest_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_2;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fftoi_d(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_2,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fftoi, mode_F, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fftoi_q(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_4,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fftoi, mode_F, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fftoi_s(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fftoi, mode_F, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fitof_d(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fitof, mode_D, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_2;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fitof_q(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fitof, sparc_mode_Q, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_4;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fitof_s(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		op0,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fitof, mode_F, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fmul_d(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_2,
		&sparc_requirements_fp_fp_2,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fmul, mode_D, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_2;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fmul_q(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_4,
		&sparc_requirements_fp_fp_4,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fmul, sparc_mode_Q, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_4;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fmul_s(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fmul, mode_F, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fneg_d(dbg_info *dbgi, ir_node *block, ir_node *val, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_2,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fneg, mode_D, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_2;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fneg_q(dbg_info *dbgi, ir_node *block, ir_node *val, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_4,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fneg, sparc_mode_Q, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_4;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fneg_s(dbg_info *dbgi, ir_node *block, ir_node *val, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		val,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fneg, mode_F, 1, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fsub_d(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_2,
		&sparc_requirements_fp_fp_2,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fsub, mode_D, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_2;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fsub_q(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_requirements_fp_fp_4,
		&sparc_requirements_fp_fp_4,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fsub, sparc_mode_Q, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_requirements_fp_fp_4;

	verify_new_node(res);
	return optimize_node(res);
}

ir_node *new_bd_sparc_fsub_s(dbg_info *dbgi, ir_node *block, ir_node *left, ir_node *right, ir_mode *fp_mode)
{
	static arch_register_req_t const *in_reqs[] = {
		&sparc_class_reg_req_fp,
		&sparc_class_reg_req_fp,
	};

	/* construct in array */
	ir_node *const in[] = {
		left,
		right,
	};

	ir_graph *const irg = get_irn_irg(block);
	ir_node  *const res = new_ir_node(dbgi, irg, block, op_sparc_fsub, mode_F, 2, in);

	/* init node attributes */

	/* flags */
	arch_irn_flags_t irn_flags = arch_irn_flags_none;
	irn_flags |= arch_irn_flag_rematerializable;
	int const n_res = 1;
	be_info_init_irn(res, irn_flags, in_reqs, n_res);
	sparc_fp_attr_t *const attr = (sparc_fp_attr_t*)get_irn_generic_attr(res);
	(void)attr; /* avoid potential warning */
	init_sparc_fp_attributes(res, fp_mode);
	reg_out_info_t *const out_infos = be_get_info(res)->out_infos;
	out_infos[0].req = &sparc_class_reg_req_fp;

	verify_new_node(res);
	return optimize_node(res);
}


/**
 * Creates the sparc specific Firm machine operations
 * needed for the assembler irgs.
 */
void sparc_create_opcodes(void)
{
	ir_op *op;
	int    cur_opcode = get_next_ir_opcodes(iro_sparc_last);

	sparc_opcode_start = cur_opcode;
	op = new_ir_op(cur_opcode + iro_sparc_Add, "sparc_Add", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Add = op;
	op = new_ir_op(cur_opcode + iro_sparc_AddCC, "sparc_AddCC", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_AddCC = op;
	op = new_ir_op(cur_opcode + iro_sparc_AddCC_t, "sparc_AddCC_t", op_pin_state_floats, irop_flag_none, oparity_any, -1, 0);
	set_op_dump(op, NULL);
	set_op_tag(op, sparc_op_tag);
	op_sparc_AddCC_t = op;
	op = new_ir_op(cur_opcode + iro_sparc_AddSP, "sparc_AddSP", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_AddSP = op;
	op = new_ir_op(cur_opcode + iro_sparc_AddX, "sparc_AddX", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_AddX = op;
	op = new_ir_op(cur_opcode + iro_sparc_AddX_t, "sparc_AddX_t", op_pin_state_floats, irop_flag_none, oparity_any, -1, 0);
	set_op_dump(op, NULL);
	set_op_tag(op, sparc_op_tag);
	op_sparc_AddX_t = op;
	op = new_ir_op(cur_opcode + iro_sparc_And, "sparc_And", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_And = op;
	op = new_ir_op(cur_opcode + iro_sparc_AndCCZero, "sparc_AndCCZero", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_AndCCZero = op;
	op = new_ir_op(cur_opcode + iro_sparc_AndN, "sparc_AndN", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_AndN = op;
	op = new_ir_op(cur_opcode + iro_sparc_AndNCCZero, "sparc_AndNCCZero", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_AndNCCZero = op;
	op = new_ir_op(cur_opcode + iro_sparc_Ba, "sparc_Ba", op_pin_state_pinned, irop_flag_cfopcode, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Ba = op;
	op = new_ir_op(cur_opcode + iro_sparc_Bicc, "sparc_Bicc", op_pin_state_pinned, irop_flag_cfopcode|irop_flag_forking, oparity_any, -1, sizeof(sparc_jmp_cond_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_jmp_cond_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Bicc = op;
	op = new_ir_op(cur_opcode + iro_sparc_Call, "sparc_Call", op_pin_state_exc_pinned, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Call = op;
	op = new_ir_op(cur_opcode + iro_sparc_Cas, "sparc_Cas", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(sparc_attr_t));
	ir_op_set_memory_index(op, 3);	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Cas = op;
	op = new_ir_op(cur_opcode + iro_sparc_Cmp, "sparc_Cmp", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Cmp = op;
	op = new_ir_op(cur_opcode + iro_sparc_FrameAddr, "sparc_FrameAddr", op_pin_state_floats, irop_flag_constlike, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_FrameAddr = op;
	op = new_ir_op(cur_opcode + iro_sparc_IJmp, "sparc_IJmp", op_pin_state_pinned, irop_flag_cfopcode|irop_flag_forking, oparity_any, -1, sizeof(sparc_load_store_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_load_store_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_IJmp = op;
	op = new_ir_op(cur_opcode + iro_sparc_Ld, "sparc_Ld", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(sparc_load_store_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_load_store_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Ld = op;
	op = new_ir_op(cur_opcode + iro_sparc_Ldf, "sparc_Ldf", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(sparc_load_store_attr_t));
	ir_op_set_memory_index(op, 1);	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_load_store_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Ldf = op;
	op = new_ir_op(cur_opcode + iro_sparc_Or, "sparc_Or", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Or = op;
	op = new_ir_op(cur_opcode + iro_sparc_OrCCZero, "sparc_OrCCZero", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_OrCCZero = op;
	op = new_ir_op(cur_opcode + iro_sparc_OrN, "sparc_OrN", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_OrN = op;
	op = new_ir_op(cur_opcode + iro_sparc_OrNCCZero, "sparc_OrNCCZero", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_OrNCCZero = op;
	op = new_ir_op(cur_opcode + iro_sparc_Restore, "sparc_Restore", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Restore = op;
	op = new_ir_op(cur_opcode + iro_sparc_RestoreZero, "sparc_RestoreZero", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_RestoreZero = op;
	op = new_ir_op(cur_opcode + iro_sparc_Return, "sparc_Return", op_pin_state_pinned, irop_flag_cfopcode, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Return = op;
	op = new_ir_op(cur_opcode + iro_sparc_SDiv, "sparc_SDiv", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(sparc_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_SDiv = op;
	op = new_ir_op(cur_opcode + iro_sparc_SMul, "sparc_SMul", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_SMul = op;
	op = new_ir_op(cur_opcode + iro_sparc_SMulCCZero, "sparc_SMulCCZero", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_SMulCCZero = op;
	op = new_ir_op(cur_opcode + iro_sparc_SMulh, "sparc_SMulh", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_SMulh = op;
	op = new_ir_op(cur_opcode + iro_sparc_Save, "sparc_Save", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Save = op;
	op = new_ir_op(cur_opcode + iro_sparc_SetHi, "sparc_SetHi", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_SetHi = op;
	op = new_ir_op(cur_opcode + iro_sparc_Sll, "sparc_Sll", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Sll = op;
	op = new_ir_op(cur_opcode + iro_sparc_Sra, "sparc_Sra", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Sra = op;
	op = new_ir_op(cur_opcode + iro_sparc_Srl, "sparc_Srl", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Srl = op;
	op = new_ir_op(cur_opcode + iro_sparc_St, "sparc_St", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(sparc_load_store_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_load_store_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_St = op;
	op = new_ir_op(cur_opcode + iro_sparc_Stbar, "sparc_Stbar", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(sparc_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Stbar = op;
	op = new_ir_op(cur_opcode + iro_sparc_Stf, "sparc_Stf", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(sparc_load_store_attr_t));
	ir_op_set_memory_index(op, 2);	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_load_store_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Stf = op;
	op = new_ir_op(cur_opcode + iro_sparc_Sub, "sparc_Sub", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Sub = op;
	op = new_ir_op(cur_opcode + iro_sparc_SubCC, "sparc_SubCC", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_SubCC = op;
	op = new_ir_op(cur_opcode + iro_sparc_SubCC_t, "sparc_SubCC_t", op_pin_state_floats, irop_flag_none, oparity_any, -1, 0);
	set_op_dump(op, NULL);
	set_op_tag(op, sparc_op_tag);
	op_sparc_SubCC_t = op;
	op = new_ir_op(cur_opcode + iro_sparc_SubSP, "sparc_SubSP", op_pin_state_floats, irop_flag_uses_memory, oparity_any, -1, sizeof(sparc_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_SubSP = op;
	op = new_ir_op(cur_opcode + iro_sparc_SubX, "sparc_SubX", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_SubX = op;
	op = new_ir_op(cur_opcode + iro_sparc_SubX_t, "sparc_SubX_t", op_pin_state_floats, irop_flag_none, oparity_any, -1, 0);
	set_op_dump(op, NULL);
	set_op_tag(op, sparc_op_tag);
	op_sparc_SubX_t = op;
	op = new_ir_op(cur_opcode + iro_sparc_SwitchJmp, "sparc_SwitchJmp", op_pin_state_pinned, irop_flag_cfopcode|irop_flag_forking, oparity_any, -1, sizeof(sparc_switch_jmp_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_switch_jmp_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_SwitchJmp = op;
	op = new_ir_op(cur_opcode + iro_sparc_UDiv, "sparc_UDiv", op_pin_state_exc_pinned, irop_flag_uses_memory, oparity_any, -1, sizeof(sparc_attr_t));
	ir_op_set_memory_index(op, 0);	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_UDiv = op;
	op = new_ir_op(cur_opcode + iro_sparc_UMulh, "sparc_UMulh", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_UMulh = op;
	op = new_ir_op(cur_opcode + iro_sparc_XNor, "sparc_XNor", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_XNor = op;
	op = new_ir_op(cur_opcode + iro_sparc_XNorCCZero, "sparc_XNorCCZero", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_XNorCCZero = op;
	op = new_ir_op(cur_opcode + iro_sparc_Xor, "sparc_Xor", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_Xor = op;
	op = new_ir_op(cur_opcode + iro_sparc_XorCCZero, "sparc_XorCCZero", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_XorCCZero = op;
	op = new_ir_op(cur_opcode + iro_sparc_fabs, "sparc_fabs", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_fp_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_fp_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_fabs = op;
	op = new_ir_op(cur_opcode + iro_sparc_fadd, "sparc_fadd", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_fp_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_fp_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_fadd = op;
	op = new_ir_op(cur_opcode + iro_sparc_fbfcc, "sparc_fbfcc", op_pin_state_pinned, irop_flag_cfopcode|irop_flag_forking, oparity_any, -1, sizeof(sparc_jmp_cond_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_jmp_cond_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_fbfcc = op;
	op = new_ir_op(cur_opcode + iro_sparc_fcmp, "sparc_fcmp", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_fp_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_fp_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_fcmp = op;
	op = new_ir_op(cur_opcode + iro_sparc_fdiv, "sparc_fdiv", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_fp_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_fp_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_fdiv = op;
	op = new_ir_op(cur_opcode + iro_sparc_fftof, "sparc_fftof", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_fp_conv_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_fp_conv_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_fftof = op;
	op = new_ir_op(cur_opcode + iro_sparc_fftoi, "sparc_fftoi", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_fp_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_fp_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_fftoi = op;
	op = new_ir_op(cur_opcode + iro_sparc_fitof, "sparc_fitof", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_fp_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_fp_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_fitof = op;
	op = new_ir_op(cur_opcode + iro_sparc_fmul, "sparc_fmul", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_fp_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_fp_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_fmul = op;
	op = new_ir_op(cur_opcode + iro_sparc_fneg, "sparc_fneg", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_fp_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_fp_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_fneg = op;
	op = new_ir_op(cur_opcode + iro_sparc_fsub, "sparc_fsub", op_pin_state_floats, irop_flag_none, oparity_any, -1, sizeof(sparc_fp_attr_t));
	set_op_dump(op, sparc_dump_node);
	set_op_attrs_equal(op, sparc_fp_attrs_equal);
	set_op_copy_attr(op, be_copy_attr);
	set_op_tag(op, sparc_op_tag);
	op_sparc_fsub = op;

}

void sparc_free_opcodes(void)
{
	free_ir_op(op_sparc_Add); op_sparc_Add = NULL;
	free_ir_op(op_sparc_AddCC); op_sparc_AddCC = NULL;
	free_ir_op(op_sparc_AddCC_t); op_sparc_AddCC_t = NULL;
	free_ir_op(op_sparc_AddSP); op_sparc_AddSP = NULL;
	free_ir_op(op_sparc_AddX); op_sparc_AddX = NULL;
	free_ir_op(op_sparc_AddX_t); op_sparc_AddX_t = NULL;
	free_ir_op(op_sparc_And); op_sparc_And = NULL;
	free_ir_op(op_sparc_AndCCZero); op_sparc_AndCCZero = NULL;
	free_ir_op(op_sparc_AndN); op_sparc_AndN = NULL;
	free_ir_op(op_sparc_AndNCCZero); op_sparc_AndNCCZero = NULL;
	free_ir_op(op_sparc_Ba); op_sparc_Ba = NULL;
	free_ir_op(op_sparc_Bicc); op_sparc_Bicc = NULL;
	free_ir_op(op_sparc_Call); op_sparc_Call = NULL;
	free_ir_op(op_sparc_Cas); op_sparc_Cas = NULL;
	free_ir_op(op_sparc_Cmp); op_sparc_Cmp = NULL;
	free_ir_op(op_sparc_FrameAddr); op_sparc_FrameAddr = NULL;
	free_ir_op(op_sparc_IJmp); op_sparc_IJmp = NULL;
	free_ir_op(op_sparc_Ld); op_sparc_Ld = NULL;
	free_ir_op(op_sparc_Ldf); op_sparc_Ldf = NULL;
	free_ir_op(op_sparc_Or); op_sparc_Or = NULL;
	free_ir_op(op_sparc_OrCCZero); op_sparc_OrCCZero = NULL;
	free_ir_op(op_sparc_OrN); op_sparc_OrN = NULL;
	free_ir_op(op_sparc_OrNCCZero); op_sparc_OrNCCZero = NULL;
	free_ir_op(op_sparc_Restore); op_sparc_Restore = NULL;
	free_ir_op(op_sparc_RestoreZero); op_sparc_RestoreZero = NULL;
	free_ir_op(op_sparc_Return); op_sparc_Return = NULL;
	free_ir_op(op_sparc_SDiv); op_sparc_SDiv = NULL;
	free_ir_op(op_sparc_SMul); op_sparc_SMul = NULL;
	free_ir_op(op_sparc_SMulCCZero); op_sparc_SMulCCZero = NULL;
	free_ir_op(op_sparc_SMulh); op_sparc_SMulh = NULL;
	free_ir_op(op_sparc_Save); op_sparc_Save = NULL;
	free_ir_op(op_sparc_SetHi); op_sparc_SetHi = NULL;
	free_ir_op(op_sparc_Sll); op_sparc_Sll = NULL;
	free_ir_op(op_sparc_Sra); op_sparc_Sra = NULL;
	free_ir_op(op_sparc_Srl); op_sparc_Srl = NULL;
	free_ir_op(op_sparc_St); op_sparc_St = NULL;
	free_ir_op(op_sparc_Stbar); op_sparc_Stbar = NULL;
	free_ir_op(op_sparc_Stf); op_sparc_Stf = NULL;
	free_ir_op(op_sparc_Sub); op_sparc_Sub = NULL;
	free_ir_op(op_sparc_SubCC); op_sparc_SubCC = NULL;
	free_ir_op(op_sparc_SubCC_t); op_sparc_SubCC_t = NULL;
	free_ir_op(op_sparc_SubSP); op_sparc_SubSP = NULL;
	free_ir_op(op_sparc_SubX); op_sparc_SubX = NULL;
	free_ir_op(op_sparc_SubX_t); op_sparc_SubX_t = NULL;
	free_ir_op(op_sparc_SwitchJmp); op_sparc_SwitchJmp = NULL;
	free_ir_op(op_sparc_UDiv); op_sparc_UDiv = NULL;
	free_ir_op(op_sparc_UMulh); op_sparc_UMulh = NULL;
	free_ir_op(op_sparc_XNor); op_sparc_XNor = NULL;
	free_ir_op(op_sparc_XNorCCZero); op_sparc_XNorCCZero = NULL;
	free_ir_op(op_sparc_Xor); op_sparc_Xor = NULL;
	free_ir_op(op_sparc_XorCCZero); op_sparc_XorCCZero = NULL;
	free_ir_op(op_sparc_fabs); op_sparc_fabs = NULL;
	free_ir_op(op_sparc_fadd); op_sparc_fadd = NULL;
	free_ir_op(op_sparc_fbfcc); op_sparc_fbfcc = NULL;
	free_ir_op(op_sparc_fcmp); op_sparc_fcmp = NULL;
	free_ir_op(op_sparc_fdiv); op_sparc_fdiv = NULL;
	free_ir_op(op_sparc_fftof); op_sparc_fftof = NULL;
	free_ir_op(op_sparc_fftoi); op_sparc_fftoi = NULL;
	free_ir_op(op_sparc_fitof); op_sparc_fitof = NULL;
	free_ir_op(op_sparc_fmul); op_sparc_fmul = NULL;
	free_ir_op(op_sparc_fneg); op_sparc_fneg = NULL;
	free_ir_op(op_sparc_fsub); op_sparc_fsub = NULL;

}
