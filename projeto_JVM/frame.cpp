#include "frame.hpp"

Frame::Frame(Class *r, Code *c, Exceptions *e, int eCount, char *rType) {
	pc = 0;
	retpc = 0;
	classref = r;
	code = c;
	exceptions_count = eCount;
	exceptions = e;
	returnType = rType;
	opStack = new OperandStack(code->max_stack);
	varArray = new LocalVariableArray(code->max_locals);
}

void Frame::bipush(u1 in) {
	opStack->bipush(in);
}

void Frame::sipush(u2 in) {
	opStack->sipush(in);
}

void Frame::pop() {
	(void)opStack->pop();
}

void Frame::pop2() {
	(void)opStack->pop();
	(void)opStack->pop();
}

void Frame::dup() {
	opStack->dup();
}

void Frame::dup2() {
	opStack->dup2();
}

void Frame::swap() {
	opStack->swap();
}

void Frame::ifeq(u2 branch) {
	if(opStack->ifzero()) {
		pc = (int)branch;
	}
}

void Frame::ifnull(u2 branch) {
	if(opStack->ifzero()) {
		pc = (int)branch;
	}
}

void Frame::ifgt(u2 branch) {
	if(opStack->ifgt()) {
		pc = (int)branch;
	}
}

void Frame::ifge(u2 branch) {
	if(!opStack->iflt()) {
		pc = (int)branch;
	}
}

void Frame::iflt(u2 branch) {
	if(opStack->iflt()) {
		pc = (int)branch;
	}
}

void Frame::ifle(u2 branch) {
	if(!opStack->ifgt()) {
		pc = (int)branch;
	}
}

void Frame::ifne(u2 branch) {
	if(!opStack->ifzero()) {
		pc = (int)branch;
	}
}

void Frame::ifnonnull(u2 branch) {
	if(!opStack->ifzero()) {
		pc = (int)branch;
	}
}

void Frame::if_icmpeq(u2 branch) {
	
	if(opStack->if_cmpeq(TYPE_INT)) {
		pc = (int)branch;
	}
}

void Frame::if_icmpgt(u2 branch) {
	if(opStack->if_icmpgt()) {
		pc = (int)branch;
	}
}

void Frame::if_icmpge(u2 branch) {
	if(!opStack->if_icmplt()) {
		pc = (int)branch;
	}
}

void Frame::if_icmplt(u2 branch) {
	if(opStack->if_icmplt()) {
		pc = (int)branch;
	}
}

void Frame::if_icmple(u2 branch) {
	if(!opStack->if_icmpgt()) {
		pc = (int)branch;
	}
}

void Frame::if_icmpne(u2 branch) {
	if(!opStack->if_cmpeq(TYPE_INT)) {
		pc = (int)branch;
	}
}

void Frame::if_acmpeq(u2 branch) {
	
	if(opStack->if_cmpeq(TYPE_REF)) {
		pc = (int)branch;
	}
}

void Frame::if_acmpne(u2 branch) {
	if(!opStack->if_cmpeq(TYPE_REF)) {
		pc = (int)branch;
	}
}

void Frame::iadd() {
	opStack->iadd();
}

void Frame::isub() {
	opStack->isub();
}

void Frame::imul() {
	opStack->imul();
}

void Frame::idiv() {
	opStack->idiv();
}

void Frame::irem() {
	opStack->irem();
}

void Frame::ineg() {
	opStack->ineg();
}

void Frame::ladd() {
	opStack->ladd();
}

void Frame::lsub() {
	opStack->lsub();
}

void Frame::lmul() {
	opStack->lmul();
}

void Frame::ldiv() {
	opStack->ldiv();
}

void Frame::lneg() {
	opStack->lneg();
}

void Frame::fneg() {
	opStack->fneg();
}

void Frame::dneg() {
	opStack->dneg();
}

void Frame::ldc(u1 cp_index) {
	char tag = classref->get_cp_tag(cp_index);
	u4 byte = classref->get_cp_bytes(cp_index);
	Operand op;
	if(tag == TAG_STRING) {
		
	} else if(tag == TAG_INTEGER) {
		op.set_byte(TYPE_INT, byte);
	} else if(tag == TAG_FLOAT) {
		op.set_byte(TYPE_FLOAT, byte);
	} else {
		printf("Error wrong cp tag for ldc %d: frame.ldc\n",tag);
		exit(0);
	}
	opStack->push(op);
}

void Frame::ldc_w(u2 cp_index) {
	char tag = classref->get_cp_tag(cp_index);
	u4 byte = classref->get_cp_bytes(cp_index);
	Operand op;
	if(tag == TAG_STRING) {
		
	} else if(tag == TAG_INTEGER) {
		op.set_byte(TYPE_INT, byte);
	} else if(tag == TAG_FLOAT) {
		op.set_byte(TYPE_FLOAT, byte);
	} else {
		printf("Error wrong cp tag for ldc_w %d: frame.ldc_w\n",tag);
		exit(0);
	}
	opStack->push(op);
}

void Frame::ldc2_w(u2 cp_index) {
	char tag = classref->get_cp_tag(cp_index);
	u4 byte1 = classref->get_cp_bytes(cp_index);
	u4 byte2 = classref->get_cp_bytes(cp_index+1);
	Operand op1, op2;
		
	if(tag == TAG_LONG) {
		op1.set_byte(TYPE_LONG, byte1);
		op2.set_byte(TYPE_LONG, byte2);
	} else if(tag == TAG_DOUBLE) {
		op1.set_byte(TYPE_DOUBLE, byte1);
		op2.set_byte(TYPE_DOUBLE, byte2);
	} else {
		printf("Error wrong cp tag for ldc2_w %d: frame.ldc2_w\n",tag);
		exit(0);
	}
	opStack->push(op1);
	opStack->push(op2);
}

void Frame::iinc(u1 index, u1 value) {
	varArray->iinc(index, value);
}
	
void Frame::iconst_m1() {
	opStack->iconst(-1);
}

void Frame::iconst_0() {
	opStack->iconst(0);
}

void Frame::iconst_1() {
	opStack->iconst(1);
}

void Frame::iconst_2() {
	opStack->iconst(2);
}

void Frame::iconst_3() {
	opStack->iconst(3);
}

void Frame::iconst_4() {
	opStack->iconst(4);
}

void Frame::iconst_5() {
	opStack->iconst(5);
}

void Frame::fconst_0() {
	opStack->fconst(0.0F);
}

void Frame::fconst_1() {
	opStack->fconst(1.0F);
}

void Frame::fconst_2() {
	opStack->fconst(2.0F);
}

void Frame::lconst_0() {
	opStack->lconst(0);
}

void Frame::lconst_1() {
	opStack->lconst(1);
}

void Frame::dconst_0() {
	opStack->dconst(0);
}

void Frame::dconst_1() {
	opStack->dconst(1);
}

void Frame::aconst_null() {
	opStack->aconst_null();
}

void Frame::iload(u2 index) {
	Operand op;
	op = varArray->load(index);
	if(op.type != TYPE_INT) {
		printf("Error value type %c != %c index[%d]: frame.iload\n",TYPE_INT,op.type,index);
		exit(0);
	}
	opStack->push(op);
}

void Frame::lload(u2 index) {
	Operand op;
	op = varArray->load(index);
	if(op.type != TYPE_LONG) {
		printf("Error value type %c != %c index[%d]: frame.lload\n",TYPE_LONG,op.type,index);
		exit(0);
	}
	opStack->push(op);
}

void Frame::fload(u2 index) {
	Operand op;
	op = varArray->load(index);
	if(op.type != TYPE_FLOAT) {
		printf("Error value type %c != %c index[%d]: frame.fload\n",TYPE_FLOAT,op.type,index);
		exit(0);
	}
	opStack->push(op);
}

void Frame::dload(u2 index) {
	Operand op;
	op = varArray->load(index);
	if(op.type != TYPE_DOUBLE) {
		printf("Error value type %c != %c index[%d]: frame.dload\n",TYPE_DOUBLE,op.type,index);
		exit(0);
	}
	opStack->push(op);
}

void Frame::aload(u2 index) {
	Operand op;
	op = varArray->load(index);
	if(op.type != TYPE_REF) {
		printf("Error value type %c != %c index[%d]: frame.aload\n",TYPE_REF,op.type,index);
		exit(0);
	}
	opStack->push(op);
}

void Frame::iload_0(){
	iload(0);
}

void Frame::iload_1(){
	iload(1);
}

void Frame::iload_2(){
	iload(2);
}

void Frame::iload_3(){
	iload(3);
}

void Frame::lload_0(){
	lload(0);
}

void Frame::lload_1(){
	lload(1);
}

void Frame::lload_2(){
	lload(2);
}

void Frame::lload_3(){
	lload(3);
}

void Frame::fload_0(){
	fload(0);
}

void Frame::fload_1(){
	fload(1);
}

void Frame::fload_2(){
	fload(2);
}

void Frame::fload_3(){
	fload(3);
}

void Frame::dload_0(){
	dload(0);
}

void Frame::dload_1(){
	dload(1);
}

void Frame::dload_2(){
	dload(2);
}

void Frame::dload_3(){
	dload(3);
}

void Frame::aload_0(){
	aload(0);
}

void Frame::aload_1(){
	aload(1);
}

void Frame::aload_2(){
	aload(2);
}

void Frame::aload_3(){
	aload(3);
}

void Frame::istore(u2 index) {
	Operand op;
	op = opStack->pop();
	if(op.type != TYPE_INT) {
		printf("Error value type %c != %c index[%d]: frame.istore\n",TYPE_INT,op.type,index);
		exit(0);
	}
	varArray->store(index, op);
}

void Frame::lstore(u2 index) {
	Operand op;
	op = opStack->pop();
	if(op.type != TYPE_LONG) {
		printf("Error value type %c != %c index[%d]: frame.lstore\n",TYPE_LONG,op.type,index);
		exit(0);
	}
	varArray->store(index, op);
}

void Frame::fstore(u2 index) {
	Operand op;
	op = opStack->pop();
	if(op.type != TYPE_FLOAT) {
		printf("Error value type %c != %c index[%d]: frame.fstore\n",TYPE_FLOAT,op.type,index);
		exit(0);
	}
	varArray->store(index, op);
}

void Frame::dstore(u2 index) {
	Operand op;
	op = opStack->pop();
	if(op.type != TYPE_DOUBLE) {
		printf("Error value type %c != %c index[%d]: frame.dstore\n",TYPE_DOUBLE,op.type,index);
		exit(0);
	}
	varArray->store(index, op);
}

void Frame::astore(u2 index) {
	Operand op;
	op = opStack->pop();
	if(op.type != TYPE_REF) {
		printf("Error value type %c != %c index[%d]: frame.astore\n",TYPE_REF,op.type,index);
		exit(0);
	}
	varArray->store(index,op);
}

void Frame::istore_0() {
	istore(0);
}

void Frame::istore_1() {
	istore(1);
}

void Frame::istore_2() {
	istore(2);
}

void Frame::istore_3() {
	istore(3);
}

void Frame::lstore_0() {
	lstore(0);
}

void Frame::lstore_1() {
	lstore(1);
}

void Frame::lstore_2() {
	lstore(2);
}

void Frame::lstore_3() {
	lstore(3);
}

void Frame::fstore_0() {
	fstore(0);
}

void Frame::fstore_1() {
	fstore(1);
}

void Frame::fstore_2() {
	fstore(2);
}

void Frame::fstore_3() {
	fstore(3);
}

void Frame::dstore_0() {
	dstore(0);
}

void Frame::dstore_1() {
	dstore(1);
}

void Frame::dstore_2() {
	dstore(2);
}

void Frame::dstore_3() {
	dstore(3);
}

void Frame::astore_0() {
	astore(0);
}

void Frame::astore_1() {
	astore(1);
}

void Frame::astore_2() {
	astore(2);
}

void Frame::astore_3() {
	astore(3);
}
	
u1 Frame::getCode() {
	u1 c = code->code[pc];
	pc++;
	return c;
}

void Frame::pcNext() {
	pc++;
}

void Frame::pcBack(int back) {
	if(back > pc) {
		printf("Error : frame:pcBack\n");
		exit(0);
	}
	pc -= back;
}

void Frame::setParam(Operand *param, int count, int ini) {
	varArray->set_param(param, count, ini);
}

Operand *Frame::popParam(int count) {
	opStack->pop_param(count);
}

void Frame::pushOpStack(u1 type, u4 value){
	Operand op;
	op.set_byte(type, value);
	opStack->push(op);
}

u4 Frame::popOpStack(){
	Operand op;
	op = opStack->pop();
	return op.bytes;
}

u4 Frame::getOpStackTop(){
	Operand op;
	op = *(opStack->top);
	return op.bytes;
}

void Frame::print() {
	printf(">>Frame\n");
	printf("  method: %s.", classref->get_cp_this_class());
	printf("%s ", methodname);
	printf("return %s\n", returnType);
	printf("  pc: %d\n", pc);
	opStack->print_min();
	varArray->print_min();
}