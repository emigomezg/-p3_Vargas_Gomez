/*
 * mouse_and_keyboard.c
 *
 *  Created on: Nov 2, 2020
 *      Author: Emiliano
 */


#include <mouse_and_keyboard.h>

#define KEYBOARD_DELAY 2000000U
#define MOUSE_DELAY 10000U


typedef enum {
	ST0,
	ST1,
	ST2,
	ST3,
	ST4,
	ST5,
	ST6,
	ST7,
	ST8,
	ST9,
	ST10,
	ST11,
	ST12,
	ST13,
	ST14,
	ST15,
}state_machine_t;

static void realese_Key (uint8_t* keybuffer);

static state_machine_t actual_machine_state_g = ST0;

static int8_t g_x = 0U;
static int8_t g_y = 0U;

static void delay(uint32_t max)
{
	uint32_t delay_counter = 0;
	while (max > delay_counter)
		delay_counter++;
}


Boolean_t squareTest(uint8_t* mouse_keyboard_buffer)
{
	static Boolean_t flag = FALSE;
	switch (actual_machine_state_g)
	{
		case ST0:
			/* Move right */
			mouse_keyboard_buffer[0] = 1U;
			mouse_keyboard_buffer[2] = 2U;
			mouse_keyboard_buffer[3] = 0U;

			g_x++;
			if (g_x > 99U) {
				actual_machine_state_g++;
			}
			break;

		case ST1:
			/* Move down */
			mouse_keyboard_buffer[0] = 1U;
			mouse_keyboard_buffer[2] = 0U;
			mouse_keyboard_buffer[3] = 2U;
			g_y++;
			if (g_y > 99U) {
				actual_machine_state_g++;
			}
			break;
		case ST2:
			/* Move left */
			mouse_keyboard_buffer[0] = 1U;
			mouse_keyboard_buffer[2] = (uint8_t) (-2);
			mouse_keyboard_buffer[3] = 0U;
			g_x--;
			if (g_x < 2U) {
				actual_machine_state_g++;
			}
			break;
		case ST3:
			/* Move up */
			mouse_keyboard_buffer[0] = 1U;
			mouse_keyboard_buffer[2] = 0U;
			mouse_keyboard_buffer[3] = (uint8_t) (-2);
			g_y--;
			if (g_y < 2U) {
				actual_machine_state_g = ST0;
				flag = TRUE;
				delay(MOUSE_DELAY);
			}
			break;
		default:
			break;
		}
	return flag;
}

Boolean_t openPaint(uint8_t* mouse_keyboard_buffer)
{
	static Boolean_t flag = FALSE;
	switch (actual_machine_state_g)
	{
	case ST0:
		/* WINDOWS + R*/
		mouse_keyboard_buffer[1] = MODIFERKEYS_LEFT_GUI;
		mouse_keyboard_buffer[3] = KEY_R;
		delay(KEYBOARD_DELAY);
		break;
	case ST1:
		/* write M*/
		mouse_keyboard_buffer[3] = KEY_M;
		delay(KEYBOARD_DELAY);
		break;
	case ST2:
		/* write S*/
		mouse_keyboard_buffer[3] = KEY_S;
		delay(KEYBOARD_DELAY);
		break;
	case ST3:
		/* write P*/
		mouse_keyboard_buffer[3] = KEY_P;
		delay(KEYBOARD_DELAY);
		break;
	case ST4:
		/* write A*/
		mouse_keyboard_buffer[3] = KEY_A;
		delay(KEYBOARD_DELAY);
		break;
	case ST5:
		/* write I*/
		mouse_keyboard_buffer[3] = KEY_I;
		delay(KEYBOARD_DELAY);
		break;
	case ST6:
		/* write N*/
		mouse_keyboard_buffer[3] = KEY_N;
		delay(KEYBOARD_DELAY);
		break;
	case ST7:
		/* write T*/
		mouse_keyboard_buffer[3] = KEY_T;
		delay(KEYBOARD_DELAY);
		break;
	case ST8:
		/* ENTER*/
		mouse_keyboard_buffer[3] = KEY_ENTER;
		delay(KEYBOARD_DELAY);
		break;
	default:
		realese_Key(mouse_keyboard_buffer);
		delay(10*KEYBOARD_DELAY);
		break;
	}

	if (actual_machine_state_g == ST9)
	{

		actual_machine_state_g = ST0;
		delay(KEYBOARD_DELAY);
		flag = TRUE;

	}
	else
	{
		delay(KEYBOARD_DELAY);
		actual_machine_state_g++;
	}
	return flag;

}

Boolean_t draw4(uint8_t* mouse_keyboard_buffer)
{
	static Boolean_t flag = FALSE;

	switch (actual_machine_state_g) {
	case ST0:
		/* Move down left */
		mouse_keyboard_buffer[1] = 1U;
		mouse_keyboard_buffer[2] = (uint8_t) (-3);
		mouse_keyboard_buffer[3] = 5U;

		g_x++;
		if (g_x > 75U) {
			actual_machine_state_g++;
		}
		break;

	case ST1:
		/* Move right */
		mouse_keyboard_buffer[1] = 1U;
		mouse_keyboard_buffer[2] = 3U;
		mouse_keyboard_buffer[3] = 0U;
		g_y++;
		if (g_y > 99U) {
			actual_machine_state_g++;
		}
		break;
	case ST2:
		/* Move up */
		mouse_keyboard_buffer[1] = 1U;
		mouse_keyboard_buffer[2] = 0U;
		mouse_keyboard_buffer[3] = (uint8_t) (-6);
		g_x--;
		if (g_x < 12U) {
			actual_machine_state_g++;
		}
		break;
	case ST3:
		/* Move down */
		mouse_keyboard_buffer[1] = 1U;
		mouse_keyboard_buffer[2] = 0U;
		mouse_keyboard_buffer[3] = 6U;
		g_y--;
		if (g_y < 2U) {
			actual_machine_state_g++;
		}
		break;
	case ST4:
		/* CLICK */
		mouse_keyboard_buffer[1] = 1U;
		mouse_keyboard_buffer[2] = 0U;
		mouse_keyboard_buffer[3] = 0U;
		g_y--;
		if (g_y < 2U) {
			actual_machine_state_g++;

		}
		break;
	case ST5:
		mouse_keyboard_buffer[1] = 0U;
		mouse_keyboard_buffer[2] = 0U;
		mouse_keyboard_buffer[3] = 0U;
		actual_machine_state_g = ST0;
		flag = TRUE;
		delay(MOUSE_DELAY);
	break;
	default:

		break;
	}

	return flag;
}

Boolean_t openNotepad(uint8_t* mouse_keyboard_buffer)
{
	static Boolean_t flag = FALSE;
	static direction_t direction = LEFT;
	switch (actual_machine_state_g) {
	case ST0:
		/* WINDOWS + R*/
		mouse_keyboard_buffer[1] = MODIFERKEYS_LEFT_GUI;
		mouse_keyboard_buffer[3] = KEY_R;
		delay(KEYBOARD_DELAY);

		break;
	case ST1:
		/* write N*/
		mouse_keyboard_buffer[3] = KEY_N;
		delay(KEYBOARD_DELAY);
		break;
	case ST2:
		/* write O*/
		mouse_keyboard_buffer[3] = KEY_O;
		delay(KEYBOARD_DELAY);
		break;
	case ST3:
		/* write T*/
		mouse_keyboard_buffer[3] = KEY_T;
		delay(KEYBOARD_DELAY);
		break;
	case ST4:
		/* write E*/
		mouse_keyboard_buffer[3] = KEY_E;
		delay(KEYBOARD_DELAY);
		break;
	case ST5:
		/* write P*/
		mouse_keyboard_buffer[3] = KEY_P;
		delay(KEYBOARD_DELAY);
		break;
	case ST6:
		/* write A*/
		mouse_keyboard_buffer[3] = KEY_A;
		delay(KEYBOARD_DELAY);
		break;
	case ST7:
		/* write D*/
		mouse_keyboard_buffer[3] = KEY_D;
		delay(KEYBOARD_DELAY);
		break;
	case ST8:
		/* ENTER*/
		mouse_keyboard_buffer[3] = KEY_ENTER;
		delay(KEYBOARD_DELAY);
		break;
	case ST9:
			realese_Key(mouse_keyboard_buffer);
			delay(KEYBOARD_DELAY);
		break;
	case ST10:
		//notepad 1
		if (LEFT == direction)
		{
			/* CTRL + <- */
			mouse_keyboard_buffer[1] = MODIFERKEYS_LEFT_GUI;
			mouse_keyboard_buffer[3] = KEY_LEFTARROW;
			delay(KEYBOARD_DELAY);
			break;
		}
		else
		{ //notepad 2
			/* CTRL + ->*/
			mouse_keyboard_buffer[1] = MODIFERKEYS_LEFT_GUI;
			mouse_keyboard_buffer[3] = KEY_RIGHTARROW;
			delay(KEYBOARD_DELAY);
			break;
		}
	default:
		break;
	}

	if (actual_machine_state_g == ST10 && direction == LEFT)
	{
		direction = RIGHT;
		actual_machine_state_g = ST0;
		delay(KEYBOARD_DELAY);
	}
	else if (actual_machine_state_g == ST10 && direction == RIGHT)
	{
		actual_machine_state_g = ST0;
		delay(KEYBOARD_DELAY);
		direction = LEFT;
		flag = TRUE;
	}
	else
	{
		actual_machine_state_g++;
	}
	return flag;
}

Boolean_t moveMouse(uint8_t* mouse_keyboard_buffer, direction_t direction)
{
	static Boolean_t flag = FALSE;

	if(RIGHT == direction)
	{
		flag = FALSE;
		switch (actual_machine_state_g)
		{
			case ST0:
				/* Move right */
				mouse_keyboard_buffer[1] = 0U;
				mouse_keyboard_buffer[2] = (uint8_t) (-6);
				mouse_keyboard_buffer[3] = 0U;
				g_x--;
				if (g_x < 2U) {
					actual_machine_state_g++;
				}
				break;

			case ST1:
				/* click */
				mouse_keyboard_buffer[1] = 1U;
				mouse_keyboard_buffer[2] = 0U;
				mouse_keyboard_buffer[3] = 0U;
				actual_machine_state_g++;
				delay(MOUSE_DELAY);
				break;
			case ST2:
				/* unclick */
				mouse_keyboard_buffer[1] = 0U;
				mouse_keyboard_buffer[2] = 0U;
				mouse_keyboard_buffer[3] = 0U;
				actual_machine_state_g++;
				delay(MOUSE_DELAY);
				break;
			case ST3:
				/* unclick */
				mouse_keyboard_buffer[1] = 0U;
				mouse_keyboard_buffer[2] = 0U;
				mouse_keyboard_buffer[3] = 0U;
				actual_machine_state_g = ST0;
				flag = TRUE;
				break;
			default:
				break;
		}
	}
	else
	{
		switch (actual_machine_state_g)
		{
			case ST0:
				/* Move left */
				mouse_keyboard_buffer[1] = 0U;
				mouse_keyboard_buffer[2] = 4U;
				mouse_keyboard_buffer[3] = 0U;

				g_x++;
				if (g_x > 200U) {
					actual_machine_state_g++;
				}

				break;

			case ST1:
				/* click */
				mouse_keyboard_buffer[1] = 1U;
				mouse_keyboard_buffer[2] = 0U;
				mouse_keyboard_buffer[3] = 0U;
				actual_machine_state_g++;
				delay(MOUSE_DELAY);
				break;
			case ST2:
				/* unclick */
				mouse_keyboard_buffer[1] = 0U;
				mouse_keyboard_buffer[2] = 0U;
				mouse_keyboard_buffer[3] = 0U;
				delay(MOUSE_DELAY);
				actual_machine_state_g++;
				break;
			case ST3:
				/* unclick */
				mouse_keyboard_buffer[1] = 0U;
				mouse_keyboard_buffer[2] = 0U;
				mouse_keyboard_buffer[3] = 0U;
				actual_machine_state_g = ST0;
				flag = TRUE;
				break;
			default:
				break;
		}
	}

		return flag;

}

Boolean_t writeText(uint8_t* mouse_keyboard_buffer)
{
	static Boolean_t flag = FALSE;

	switch (actual_machine_state_g)
	{
	case ST0:
		/*  write H*/
		mouse_keyboard_buffer[3] = KEY_H;
		delay(KEYBOARD_DELAY);
		break;
	case ST1:
		/*  write A*/
		mouse_keyboard_buffer[3] = KEY_O;
		delay(KEYBOARD_DELAY);
		break;
	case ST2:
		/*  write I*/
		mouse_keyboard_buffer[3] = KEY_L;
		delay(KEYBOARD_DELAY);
		break;
	case ST3:
		/*  write L*/
		mouse_keyboard_buffer[3] = KEY_A;
		delay(KEYBOARD_DELAY);
		break;
	case ST4:
		/*  SPACEBAR */
		mouse_keyboard_buffer[3] = KEY_SPACEBAR;
		delay(KEYBOARD_DELAY);
		break;
	case ST5:
		/*  write P*/
		mouse_keyboard_buffer[3] = KEY_M;
		delay(KEYBOARD_DELAY);
		break;
	case ST6:
		/*  write I*/
		mouse_keyboard_buffer[3] = KEY_U;
		delay(KEYBOARD_DELAY);
		break;
	case ST7:
		/*  write Z*/
		mouse_keyboard_buffer[3] = KEY_N;
		delay(KEYBOARD_DELAY);
		break;
	case ST8:
		/*  write A*/
		mouse_keyboard_buffer[3] = KEY_D;
		delay(KEYBOARD_DELAY);
		break;
	case ST9:
		/*  write N*/
		mouse_keyboard_buffer[3] = KEY_O;
		delay(KEYBOARD_DELAY);
		break;
	case ST10:
		/*  write O*/
		mouse_keyboard_buffer[3] = KEY_O;
		delay(KEYBOARD_DELAY);
		break;
	case ST11:
			realese_Key(mouse_keyboard_buffer);
		break;
	default:
		break;
	}

	if (actual_machine_state_g == ST12) {
		actual_machine_state_g = ST0;
		realese_Key(mouse_keyboard_buffer);
		flag = TRUE;
		delay(10 * KEYBOARD_DELAY);
	} else {
		actual_machine_state_g++;
	}

	return flag;
}

Boolean_t copyText(uint8_t* mouse_keyboard_buffer)
{
	static Boolean_t flag = FALSE;

	switch (actual_machine_state_g) {
	case ST0:
		/* CRTL */
		mouse_keyboard_buffer[1] = MODIFERKEYS_LEFT_CTRL;
		/* DependS on the language of the computer, it could be KEY_A or KEY_E*/
		mouse_keyboard_buffer[3] = KEY_A;
		delay(KEYBOARD_DELAY);
		break;
	case ST2:
		delay(10 * KEYBOARD_DELAY);
		break;
	case ST3:
		/*  CTRL + C*/
		mouse_keyboard_buffer[1] = MODIFERKEYS_LEFT_CTRL;
		mouse_keyboard_buffer[3] = KEY_C;
		delay(KEYBOARD_DELAY);
		break;
	case ST4:
		realese_Key(mouse_keyboard_buffer);
		flag = TRUE;
		delay(KEYBOARD_DELAY);
	break;
	default:
	break;
	}

	if (actual_machine_state_g == ST4)
	{
		actual_machine_state_g = ST0;
	}
	else
	{
		actual_machine_state_g++;
	}

	return flag;
}

Boolean_t pasteText(uint8_t* mouse_keyboard_buffer)
{
	static Boolean_t flag = FALSE;

	switch (actual_machine_state_g)
	{
		case ST0:
			mouse_keyboard_buffer[1] = MODIFERKEYS_LEFT_CTRL;
			mouse_keyboard_buffer[3] = KEY_V;
			delay(KEYBOARD_DELAY);

			break;
		case ST2:
			realese_Key(mouse_keyboard_buffer);
			flag = TRUE;
			break;
		default:
			break;
	}

	if (actual_machine_state_g == ST2) {
		actual_machine_state_g = ST0;
	} else {
		actual_machine_state_g++;
	}

	return flag;
}


static void realese_Key (uint8_t* keybuffer)
{
	keybuffer[1] = 0U;
	keybuffer[3] = 0U;
	keybuffer[4] = 0U;
	keybuffer[5] = 0U;
}
