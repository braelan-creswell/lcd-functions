//lcd.h header file

#ifndef LCD_H_                          
#define LCD_H_

#define lcd_D7    26                   // lcd D7 connection


#define lcd_D6    19                   // lcd D6 connection


#define lcd_D5    13                   // lcd D5 connection


#define lcd_D4    6                   // lcd D4 connection


#define lcd_E    27                   // lcd Enable pin


#define lcd_RS    17                   // lcd Register Select pin


// LCD module information
#define lcd_LineOne     0x00                    //line 1
#define lcd_LineTwo     0x40                    //line 2


// LCD instructions
#define lcd_Clear           0b00000001          // replace all characters with space
#define lcd_Home            0b00000010          // return cursor to first position
#define lcd_EntryMode       0b00000110          
#define lcd_DisplayOff      0b00001000          // turn display off
#define lcd_DisplayOn       0b00001111          // display on, cursor on, blink character
#define lcd_FunctionReset   0b00110000          // reset
#define lcd_FunctionSet     0b00101000          // 4-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0b10000000          // set cursor position

void lcd_init(void);
void lcd_write(u_int8_t flag, u_int8_t data);
void lcd_instruct(u_int8_t instruction);
void lcd_writechar(u_int8_t data);
void lcd_print(u_int8_t *string);
void lcd_destroy(void);

#endif
