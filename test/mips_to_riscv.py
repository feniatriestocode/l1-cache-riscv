mips_instructions = open("test_instructions.txt", "r")

instructions = mips_instructions.readlines()

for instruction in instructions:
    words = instruction.split()

    if words[0] == "add":
        opcode = "0110011"
        funct3 = "000"
        funct7 = "0000000"
        rs2 = format(int(words[-1][1:]), '#07b')[2:]
        rs1 = format(int(words[-2][1:-1]), '#07b')[2:]  
        rd = format(int(words[-3][1:-1]), '#07b')[2:]
        print(funct7 + "_" + rs2 + "_" + rs1 + "_" + funct3 + "_" + rd + "_" + opcode)
    elif words[0] == "lw":
        opcode = "0000011"
        funct3 = "010"
        rd = format(int(words[-2][1:-1]), '#07b')[2:]
        imm = format(int(words[-1][0]), '#014b')[2:]
        last_dollar = instruction.rfind("$")
        rs1 = format(int(instruction[last_dollar+1:-2]), '#07b')[2:]  
        print(imm + "_" + rs1 + "_" + funct3 + "_" + rd + "_" + opcode)
    elif words[0] == "bne":
        opcode = "1100011"
        funct3 = "001"
        