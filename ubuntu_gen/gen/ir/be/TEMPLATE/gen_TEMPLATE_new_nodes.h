/**
 * @file
 * @brief Function prototypes for the new opcode functions.
 * @note  DO NOT EDIT THIS FILE, your changes will be lost.
 *        Edit /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/TEMPLATE/TEMPLATE_spec.pl instead.
 *        created by: /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/scripts/generate_new_opcodes.pl /home/heaven7/heaven7/temp/cparser/libfirm/ir/be/TEMPLATE/TEMPLATE_spec.pl /home/heaven7/heaven7/temp/build-cparser-Desktop_Qt_5_14_2_GCC_64bit-Debug/libfirm/gen/ir/be/TEMPLATE
 * @date  Mon Aug  8 09:46:25 2022
 */
#ifndef FIRM_BE_TEMPLATE_GEN_TEMPLATE_NEW_NODES_H
#define FIRM_BE_TEMPLATE_GEN_TEMPLATE_NEW_NODES_H

#include "be_types.h"
#include "irnode_t.h"
#include "TEMPLATE_nodes_attr.h"

typedef enum TEMPLATE_opcodes {
	iro_TEMPLATE_Add,
	iro_TEMPLATE_And,
	iro_TEMPLATE_Const,
	iro_TEMPLATE_Jmp,
	iro_TEMPLATE_Load,
	iro_TEMPLATE_Minus,
	iro_TEMPLATE_Mul,
	iro_TEMPLATE_Not,
	iro_TEMPLATE_Or,
	iro_TEMPLATE_Return,
	iro_TEMPLATE_Shl,
	iro_TEMPLATE_Shr,
	iro_TEMPLATE_Store,
	iro_TEMPLATE_Sub,
	iro_TEMPLATE_Xor,
	iro_TEMPLATE_fAdd,
	iro_TEMPLATE_fConst,
	iro_TEMPLATE_fDiv,
	iro_TEMPLATE_fLoad,
	iro_TEMPLATE_fMinus,
	iro_TEMPLATE_fMul,
	iro_TEMPLATE_fStore,
	iro_TEMPLATE_fSub,
	iro_TEMPLATE_last
} TEMPLATE_opcodes;


int is_TEMPLATE_irn(const ir_node *node);
int is_TEMPLATE_op(const ir_op *op);

int get_TEMPLATE_irn_opcode(const ir_node *node);
void TEMPLATE_create_opcodes(void);
void TEMPLATE_free_opcodes(void);

extern ir_op *op_TEMPLATE_Add;

static inline bool is_TEMPLATE_Add(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Add;
}

/**
 * construct Add node
 */
ir_node *new_bd_TEMPLATE_Add(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_TEMPLATE_And;

static inline bool is_TEMPLATE_And(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_And;
}

/**
 * construct And node
 */
ir_node *new_bd_TEMPLATE_And(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_TEMPLATE_Const;

static inline bool is_TEMPLATE_Const(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Const;
}

/**
 * construct Const node
 */
ir_node *new_bd_TEMPLATE_Const(dbg_info *dbgi, ir_node *block, ir_entity *entity, ir_tarval *value);

extern ir_op *op_TEMPLATE_Jmp;

static inline bool is_TEMPLATE_Jmp(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Jmp;
}

/**
 * construct Jmp node
 */
ir_node *new_bd_TEMPLATE_Jmp(dbg_info *dbgi, ir_node *block);

extern ir_op *op_TEMPLATE_Load;

static inline bool is_TEMPLATE_Load(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Load;
}

/**
 * construct Load node
 */
ir_node *new_bd_TEMPLATE_Load(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *ptr);

extern ir_op *op_TEMPLATE_Minus;

static inline bool is_TEMPLATE_Minus(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Minus;
}

/**
 * construct Minus node
 */
ir_node *new_bd_TEMPLATE_Minus(dbg_info *dbgi, ir_node *block, ir_node *op0);

extern ir_op *op_TEMPLATE_Mul;

static inline bool is_TEMPLATE_Mul(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Mul;
}

/**
 * construct Mul node
 */
ir_node *new_bd_TEMPLATE_Mul(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_TEMPLATE_Not;

static inline bool is_TEMPLATE_Not(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Not;
}

/**
 * construct Not node
 */
ir_node *new_bd_TEMPLATE_Not(dbg_info *dbgi, ir_node *block, ir_node *op0);

extern ir_op *op_TEMPLATE_Or;

static inline bool is_TEMPLATE_Or(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Or;
}

/**
 * construct Or node
 */
ir_node *new_bd_TEMPLATE_Or(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_TEMPLATE_Return;

static inline bool is_TEMPLATE_Return(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Return;
}

/**
 * construct Return node
 */
ir_node *new_bd_TEMPLATE_Return(dbg_info *dbgi, ir_node *block, int const arity, ir_node *const *const in, arch_register_req_t const **const in_reqs);

extern ir_op *op_TEMPLATE_Shl;

static inline bool is_TEMPLATE_Shl(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Shl;
}

/**
 * construct Shl node
 */
ir_node *new_bd_TEMPLATE_Shl(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_TEMPLATE_Shr;

static inline bool is_TEMPLATE_Shr(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Shr;
}

/**
 * construct Shr node
 */
ir_node *new_bd_TEMPLATE_Shr(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_TEMPLATE_Store;

static inline bool is_TEMPLATE_Store(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Store;
}

/**
 * construct Store node
 */
ir_node *new_bd_TEMPLATE_Store(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *ptr, ir_node *val);

extern ir_op *op_TEMPLATE_Sub;

static inline bool is_TEMPLATE_Sub(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Sub;
}

/**
 * construct Sub node
 */
ir_node *new_bd_TEMPLATE_Sub(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_TEMPLATE_Xor;

static inline bool is_TEMPLATE_Xor(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_Xor;
}

/**
 * construct Xor node
 */
ir_node *new_bd_TEMPLATE_Xor(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_TEMPLATE_fAdd;

static inline bool is_TEMPLATE_fAdd(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_fAdd;
}

/**
 * construct fAdd node
 */
ir_node *new_bd_TEMPLATE_fAdd(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_TEMPLATE_fConst;

static inline bool is_TEMPLATE_fConst(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_fConst;
}

/**
 * construct fConst node
 */
ir_node *new_bd_TEMPLATE_fConst(dbg_info *dbgi, ir_node *block);

extern ir_op *op_TEMPLATE_fDiv;

static inline bool is_TEMPLATE_fDiv(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_fDiv;
}

/**
 * construct fDiv node
 */
ir_node *new_bd_TEMPLATE_fDiv(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_TEMPLATE_fLoad;

static inline bool is_TEMPLATE_fLoad(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_fLoad;
}

/**
 * construct fLoad node
 */
ir_node *new_bd_TEMPLATE_fLoad(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *ptr);

extern ir_op *op_TEMPLATE_fMinus;

static inline bool is_TEMPLATE_fMinus(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_fMinus;
}

/**
 * construct fMinus node
 */
ir_node *new_bd_TEMPLATE_fMinus(dbg_info *dbgi, ir_node *block, ir_node *op0);

extern ir_op *op_TEMPLATE_fMul;

static inline bool is_TEMPLATE_fMul(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_fMul;
}

/**
 * construct fMul node
 */
ir_node *new_bd_TEMPLATE_fMul(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);

extern ir_op *op_TEMPLATE_fStore;

static inline bool is_TEMPLATE_fStore(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_fStore;
}

/**
 * construct fStore node
 */
ir_node *new_bd_TEMPLATE_fStore(dbg_info *dbgi, ir_node *block, ir_node *mem, ir_node *ptr, ir_node *val);

extern ir_op *op_TEMPLATE_fSub;

static inline bool is_TEMPLATE_fSub(ir_node const *const n)
{
	return get_irn_op(n) == op_TEMPLATE_fSub;
}

/**
 * construct fSub node
 */
ir_node *new_bd_TEMPLATE_fSub(dbg_info *dbgi, ir_node *block, ir_node *op0, ir_node *op1);


typedef enum pn_TEMPLATE_Load {
	pn_TEMPLATE_Load_res = 0,
	pn_TEMPLATE_Load_M = 1,
} pn_TEMPLATE_Load;

typedef enum n_TEMPLATE_Load {
	n_TEMPLATE_Load_mem = 0,
	n_TEMPLATE_Load_ptr = 1,
} n_TEMPLATE_Load;

typedef enum pn_TEMPLATE_Return {
	pn_TEMPLATE_Return_X = 0,
} pn_TEMPLATE_Return;

typedef enum n_TEMPLATE_Return {
	n_TEMPLATE_Return_mem = 0,
	n_TEMPLATE_Return_stack = 1,
	n_TEMPLATE_Return_first_result = 2,
} n_TEMPLATE_Return;

typedef enum pn_TEMPLATE_Store {
	pn_TEMPLATE_Store_M = 0,
} pn_TEMPLATE_Store;

typedef enum n_TEMPLATE_Store {
	n_TEMPLATE_Store_mem = 0,
	n_TEMPLATE_Store_ptr = 1,
	n_TEMPLATE_Store_val = 2,
} n_TEMPLATE_Store;

typedef enum pn_TEMPLATE_fLoad {
	pn_TEMPLATE_fLoad_res = 0,
	pn_TEMPLATE_fLoad_M = 1,
} pn_TEMPLATE_fLoad;

typedef enum n_TEMPLATE_fLoad {
	n_TEMPLATE_fLoad_mem = 0,
	n_TEMPLATE_fLoad_ptr = 1,
} n_TEMPLATE_fLoad;

typedef enum pn_TEMPLATE_fStore {
	pn_TEMPLATE_fStore_M = 0,
} pn_TEMPLATE_fStore;

typedef enum n_TEMPLATE_fStore {
	n_TEMPLATE_fStore_mem = 0,
	n_TEMPLATE_fStore_ptr = 1,
	n_TEMPLATE_fStore_val = 2,
} n_TEMPLATE_fStore;


#endif
