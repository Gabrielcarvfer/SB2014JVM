#ifndef FRAME
#define FRAME

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "local_var_array.hpp"
#include "op_stack.hpp"
#include "operand.hpp"
#include "class.hpp"


class Frame {
public:
	int pc;
	int retpc;
	Class *classref;
	Code *code;
	int exceptions_count;
	Exceptions *exceptions;
	char *returnType;
	OperandStack *opStack;
	LocalVariableArray *varArray;
	char *methodname;
	
	Frame(Class *r, Code *c, Exceptions *e, int eCount, char *rType);
	
	void bipush(u1);
	void sipush(u2);
	
	void ldc(u1);
	void ldc_w(u2);
	void ldc2_w(u2);
	
	void pop();
	void pop2();
	
	void dup();
	void dup2();
	void swap();
	/*
	void dup_x1();
	void dup2_x1();
	void dup_x2();
	void dup2_x2();
	*/
	void ifeq(u2);
	void ifnull(u2);
	void ifgt(u2);
	void ifge(u2);
	void iflt(u2);
	void ifle(u2);
	void ifne(u2);
	void ifnonnull(u2);
	
	void if_icmpeq(u2);
	void if_icmpgt(u2);
	void if_icmpge(u2);
	void if_icmplt(u2);
	void if_icmple(u2);
	void if_icmpne(u2);
	
	void if_acmpeq(u2);
	void if_acmpne(u2);
	/*
	dcompg
	dcompl
	fcompg
	fcompl
	lcmp
	*/
	void iadd();
	void isub();
	void imul();
	void idiv();
	void irem();
	void ineg();
	
	void ladd();
	void lsub();
	void lmul();
	void ldiv();
	void lrem();
	void lneg();
	
	void fadd();
	void fsub();
	void fmul();
	void fdiv();
	void frem();
	void fneg();
	
	void dneg();
	/*
	
	
	
	void dadd();
	void dsub();
	void dmul();
	void ddiv();
	void drem();
	
	i2l
	i2f
	i2d
	i2b
	i2c
	i2s
	
	l2i
	l2f
	l2d
	
	f2i
	f2l
	f2d
	
	d2i
	d2l
	d2f
	
	
	*/
	void iinc(u1, u1);
	
	void iconst_m1();
	void iconst_0();
	void iconst_1();
	void iconst_2();
	void iconst_3();
	void iconst_4();
	void iconst_5();
	void fconst_0();
	void fconst_1();
	void fconst_2();
	void lconst_0();
	void lconst_1();
	void dconst_0();
	void dconst_1();
	void aconst_null();
	
	void iload(u2);
	void lload(u2);
	void fload(u2);
	void dload(u2);
	void aload(u2);
	void iload_0();
	void iload_1();
	void iload_2();
	void iload_3();
	void lload_0();
	void lload_1();
	void lload_2();
	void lload_3();
	void fload_0();
	void fload_1();
	void fload_2();
	void fload_3();
	void dload_0();
	void dload_1();
	void dload_2();
	void dload_3();
	void aload_0();
	void aload_1();
	void aload_2();
	void aload_3();
	void istore(u2);
	void lstore(u2);
	void fstore(u2);
	void dstore(u2);
	void astore(u2);
	void istore_0();
	void istore_1();
	void istore_2();
	void istore_3();
	void lstore_0();
	void lstore_1();
	void lstore_2();
	void lstore_3();
	void fstore_0();
	void fstore_1();
	void fstore_2();
	void fstore_3();
	void dstore_0();
	void dstore_1();
	void dstore_2();
	void dstore_3();
	void astore_0();
	void astore_1();
	void astore_2();
	void astore_3();

	
	u1 getCode();
	void pcNext();
	void pcBack(int);
	void setParam(Operand *param, int count, int ini);
	Operand *popParam(int count);
	
	void pushOpStack(u1, u4);
	u4 popOpStack();
	u4 getOpStackTop();
	
	
	void print();
};


#endif
