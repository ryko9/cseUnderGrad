
#define MAXNUMINSTRS 1024	/* max # instrs in a program */
#define MAXNUMDATA 3072		/* max # data words */

struct SimulatedComputer {
    int memory [MAXNUMINSTRS+MAXNUMDATA];
    int registers [32];
    int pc;
    int printingRegisters, printingMemory, interactive, debugging;
};
typedef struct SimulatedComputer Computer;

typedef enum { R=0, I, J } InstrType;

typedef struct {
  int rs;
  int rt;
  int rd;
  int shamt;
  int funct;
} RRegs;

typedef struct {
  int rs;
  int rt;
  int addr_or_immed;
} IRegs;

typedef struct {
  int target;
} JRegs;

typedef struct {
  InstrType type;
  int op;
  union {
    RRegs r;
    IRegs i;
    JRegs j;
  } regs;
} DecodedInstr;

typedef struct {
  int R_rs; /*Value in register rs*/
  int R_rt;
  int R_rd;
} RegVals;

void InitComputer (FILE*, int printingRegisters, int printingMemory,
    int debugging, int interactive);
void Simulate ();

//opcodes correspond to specific instructions.
typedef enum {	
	sw = 0x2b,
	lw = 0x23,
	lui = 0x0f,
	ori = 0x0d,
	andi = 0x0c, 
	addiu = 0x09,
	bne = 0x05, 
	beq = 0x04,
	jal = 0x03,
	j = 0x02 
	
} opcode;

//setting MIPS functions
typedef enum {
	slt = 0x2a,
	or = 0x25,
	and = 0x24, 
	subu = 0x23,
	addu = 0x21,
	jr = 0x08,
	srl = 0x02,
	sll = 0x00 

} funct;

