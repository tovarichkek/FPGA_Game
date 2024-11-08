from PIL import Image

image = Image.open('./logo.png').convert('RGB')

with open('../logo_rom.sv','w') as f:
    f.write("module logo_rom (\n  input  wire    [16:0]     addr,\n  output wire    [11:0]     word\n);\n  logic [11:0] rom [(400 * 320)];\n  assign word = rom[addr];\n  initial begin\n")

    i = 0
    for pixel in list(image.getdata()):

        r_4 = pixel[0] >> 4
        g_4 = pixel[1] >> 4
        b_4 = pixel[2] >> 4

        res = r_4 | g_4 << 4 | b_4 << 8
        f.write("rom["+str(i) + "] = 12'", )
        f.write ('h' + f'{res:3x};\n')
        i += 1
    f.write(';')
    f.write('end\nendmodule\n')
