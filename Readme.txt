ADD:
Instruction Code: ADD rd, rs1, rs2
Opcode: 0110011
Funct7: 0000000
Funct3: 000
Example: ADD x3, x1, x2 (2nd Instruction in x.txt)
SUB:
Instruction Code: SUB rd, rs1, rs2
Opcode: 0110011
Funct7: 0100000
Funct3: 000
Example: SUB x3, x1, x2(3rd Instruction in x.txt)
ADDI:
Instruction Code: ADDI rd, rs1, imm
Opcode: 0010011
Funct3: 000
Example: ADDI x3, x1, 12(1st and 4th Instruction in x.txt)
LW:
Instruction Code: LW rd, offset(rs1)
Opcode: 0000011
Funct3: 010
Example: LW x3, 18(x1)(5th Instruction in x.txt)
SW:
Instruction Code: SW rs2, offset(rs1)
Opcode: 0100011
Funct3: 010
Example: SW x2, 18(x1)(6th Instruction in x.txt)