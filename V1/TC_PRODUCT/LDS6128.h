
/*****************************************************/
#ifndef __LDS6128_H__
#define __LDS6128_H__

#define		LDS6128_ADDR 			0x2c

extern		Bool 	    LDS6128_connect;
extern 		Bool		LDS6128_init(void);
extern 		Bool		LDS6128_detect(void);
extern 		void 		LDS6128_led_init(void);
extern 		void 		LDS6128_led_dimming(U8 loop_count);
extern		U32			LDS6128_key_status(void);

#endif  /* __LDS60XX_H__ */		