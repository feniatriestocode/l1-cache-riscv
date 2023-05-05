import sys

# Dissasembles RISC-V instructions
def hexToString(hex):
	pass

# Generates a string 
def getInstructionLine(addr, hex):
	return "@" + addr + " " + hex + " # " + hexToString((hex))

filename = sys.argv[1] if len(sys.argv) > 1 else print("Please give filename as argument.")
filenameBody = ".".join(filename.split(".")[0:-1])

print(filenameBody)