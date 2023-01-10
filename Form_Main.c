#include "logic_Form.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DOORCLOSED 0
#define COEF 1
#define LIMIT 2
#define DICEAGAIN 3

#pragma region ENUMS
enum Dice {
	DiceM3,
	DiceM2,
	DiceM1,
	DiceP1,
	DiceP2,
	DiceP3,
};
enum Dice_size
{
	DICE_L = 615,
	DICE_R = 690,
	DICE_T = 366,
	DICE_B = 440,
};
enum Nut { NUT1, NUT2, };
enum LuckyCard
{
	Place1,
	Place2,
	Place3,
	Place4,
};//hello
enum Pages
{
	StartGame,
	Form_continue,
	FristMenu,
	buttons_continueANDnew_Form,
	Template_Form,
	Guide_Form,
	AboutUs_Form,
	Setting_Form,
	Board_Form,
	appointment_Form,//TAiin Nobat
	Choose_Card,
};
enum Position_Block_OnePesonE
{
	OLT = 673,
	ORT = 1273,
	OLB = 951,
	ORB = 1273,
	OTT = 17,
	OBT = 615,
	OTB = 615,
	OBB = 781,

};
enum Position_Block_Guide
{
	PBG_L = 572,
	PBG_R = 729,
	PBG_T = 638,
	PBG_B = 795,
};
enum Position_Block_TwePesonE
{
	TwLT = 32,
	TwRT = 628,
	TwLB = 32,
	TwRB = 352,
	TwTT = 17,
	TwBT = 615,
	TwTB = 615,
	TwBB = 781,

};
enum GuideForms { P1, P2, P3, P4, P5 };
enum aboutus
{
	auL = 385,
	auR = 543,
	auT = 637,
	auB = 794,
};
enum Works_of_player
{
	CLICKDICE,
	CLICKCARD_doorclosed,
	CLICKCARD_coef,
	CLICKCARD_limit,
	CLICKCARD_diceagain,
	CLICKNUT1_P1,
	CLICKNUT2_P1,
	CLICKNUT1_P2,
	CLICKNUT2_P2,
	CLICKNUT1_ENEMY,
	CLICKNUT2_ENEMY,
};
enum Position_P1Nut1
{
	PP1N1_L = 365,
	PP1N1_T = 730,
	PPNW = 68,
};
enum Position_P1Nut2
{
	PP1N2_L = 470,
	PP1N2_T = 730,

};
enum Position_P2Nut1
{
	PP2N1_L = 760,
	PP2N1_T = 5,
};

enum Position_P2Nut2
{
	PP2N2_L = 865,
	PP2N2_T = 5,
};
enum Position_MenuInTheBoardIcon
{
	PMBI_L = 35,
	PMBI_R = 100,
	PMBI_T = -5,
	PMBI_B = 60,
};
enum Position_YesInMenuMessageInTheBoard
{
	PYIMMIB_L = 673,
	PYIMMIB_T = 515,
	PYIMMIB_R = 882,
	PYIMMIB_B = 580,
};
enum coef_card_p1
{
	zcp1_L = 227,
	zcp1_R = 350,
	zcp1_T = 430,
	zcp1_B = 500,
};
enum diceAgain_card_p1
{
	dcp1_L = 227,
	dcp1_R = 350,
	dcp1_T = 610,
	dcp1_B = 680,
};
enum limit_card_p1
{
	lcp1_L = 227,
	lcp1_R = 350,
	lcp1_T = 520,
	lcp1_B = 590,
};
enum closeDoor_card_p1
{
	cdcp1_L = 227,
	cdcp1_R = 350,
	cdcp1_T = 340,
	cdcp1_B = 410,
};
enum coef_card_p2
{
	zcp2_L = 950,
	zcp2_R = 1072,
	zcp2_T = 210,
	zcp2_B = 280,
};
enum diceAgain_card_p2
{
	dcp2_L = 950,
	dcp2_R = 1072,
	dcp2_T = 390,
	dcp2_B = 460,
};
enum limit_card_p2
{
	lcp2_L = 950,
	lcp2_R = 1072,
	lcp2_T = 299,
	lcp2_B = 368,
};
enum closeDoor_card_p2
{
	cdcp2_L = 950,
	cdcp2_R = 1072,
	cdcp2_T = 120,
	cdcp2_B = 190,
};
#pragma endregion
#pragma region STRUCTS
struct POINT
{
	int x, y;
};
struct button
{
	int X_frist, X_end;
	int Y_frist, Y_end;
	int sw_Link;
};
struct NUT
{
	int x;
	int y;
	ALLEGRO_BITMAP* picture;
};
#pragma endregion
void must_init(bool check, const char* description)
{
	if (check) return;
	printf("couldn't initialize %s\n", description);
	exit(1);
}
bool is_Position_btn(ALLEGRO_MOUSE_STATE mouseState)
{
	if (/*(mouseState.x > OLT && mouseState.x < ORT && mouseState.y>OTT && mouseState.y < OBT) ||
		(mouseState.x > OLB && mouseState.x < ORB && mouseState.y>OTB && mouseState.y < OBB) ||*/
		(mouseState.x > TwLT && mouseState.x < TwRT && mouseState.y>TwTT && mouseState.y < TwBT) ||
		(mouseState.x > TwLB && mouseState.x < TwRB && mouseState.y>TwTB && mouseState.y < TwBB) ||
		(mouseState.x > PBG_L && mouseState.x < PBG_R && mouseState.y>PBG_T && mouseState.y < PBG_B))
	{
		return true;
	}
	else return false;
}
bool sw_btn(struct button* btn, ALLEGRO_MOUSE_STATE* mouse)
{
	if (mouse->x > btn->X_frist &&
		mouse->y > btn->Y_frist &&
		mouse->x < btn->X_end &&
		mouse->y < btn->Y_end)
		return true;
	else return false;
}
int ArrayCardsPlace[9];
int ArrayCarridorsPlace[9][2] = { 0 };

int main()
{
	srand(time(0));
	//Setting
#pragma region create Window

	al_init();
	must_init(al_init(), "Allegro");
	must_init(al_init_primitives_addon(), "primitives");
	must_init(al_init_image_addon(), "Image Load");
	must_init(al_install_keyboard(), "Key Board");
	must_init(al_install_mouse(), "Mouse");

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
	must_init(timer, "timer");

	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	must_init(queue, "queue");
	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

	ALLEGRO_DISPLAY* disp = al_create_display(1300, 810);
	must_init(disp, "Window");

	ALLEGRO_FONT* font = al_create_builtin_font();

	ALLEGRO_MOUSE_STATE mouseState;

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(disp));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_mouse_event_source());

#pragma endregion


#pragma region  Variables
	bool sw = true;
	bool done = false;
	bool LinkCursor = false;
	bool Permission_change_mouse = false;
	bool sw_btnDown = false;

	bool Tik_Dice = false;
	bool Tik_Nut = false;
	bool Tik_Player = true;

	bool P1N1_IsLive = true;
	bool P1N2_IsLive = true;
	bool P2N1_IsLive = true;
	bool P2N2_IsLive = true;

	bool one_click_btn_DICEAGAIN_CARD_p1 = true;
	bool one_click_btn_DICEAGAIN_CARD_p2 = true;

	bool sw_Show_MessageBoxMenu = false;

	bool menu_massage_display = false;
	int turn = 1;
	enum Pages pages_sw = FristMenu;
	//variable LOGIC-------------------------
	bool player_Turn = P1;//turn of players

	short int IsDoorClosed = 0;

	short int CoefDice = 1;

	short int sw_AgainDice = 0;

	short int playerSW = 1;

	short int IsLimitP1 = 0;
	short int IsLimitP2 = 0;

	int CardsP1[4] = { 0 }, CardsP2[4] = { 0 };

	int Player1[2] = { 0 }, Player2[2] = { 80,80 };

	int DiceVar = 0;

	int count = 0;

	int iP1 = 0, iP2 = 0;

	int CardChoosed;

	int count_startgame = 0;

	enum Works_of_player User_operation = -1;

	//-------------------------------------------
	int load_percent = 1;

	struct button btn_Guide;
	btn_Guide.X_frist = PBG_L;
	btn_Guide.Y_frist = PBG_T;
	btn_Guide.X_end = PBG_R;
	btn_Guide.Y_end = PBG_B;
	btn_Guide.sw_Link = Guide_Form;

	struct button btn_ONEPERSON_To_buttons_continueANDnew_Form[2];
	btn_ONEPERSON_To_buttons_continueANDnew_Form[0].X_frist = OLT;
	btn_ONEPERSON_To_buttons_continueANDnew_Form[0].Y_frist = OTT;
	btn_ONEPERSON_To_buttons_continueANDnew_Form[0].X_end = ORT;
	btn_ONEPERSON_To_buttons_continueANDnew_Form[0].Y_end = OBT;
	btn_ONEPERSON_To_buttons_continueANDnew_Form[0].sw_Link = Board_Form;
	btn_ONEPERSON_To_buttons_continueANDnew_Form[1].X_frist = OLB;
	btn_ONEPERSON_To_buttons_continueANDnew_Form[1].Y_frist = OBT;
	btn_ONEPERSON_To_buttons_continueANDnew_Form[1].X_end = ORB;
	btn_ONEPERSON_To_buttons_continueANDnew_Form[1].Y_end = OBB;
	btn_ONEPERSON_To_buttons_continueANDnew_Form[1].sw_Link = Board_Form;

	struct button btn_TWEPERSON_To_buttons_continueANDnew_Form[2];
	btn_TWEPERSON_To_buttons_continueANDnew_Form[0].X_frist = TwLB;
	btn_TWEPERSON_To_buttons_continueANDnew_Form[0].Y_frist = TwTT;
	btn_TWEPERSON_To_buttons_continueANDnew_Form[0].X_end = TwRT;
	btn_TWEPERSON_To_buttons_continueANDnew_Form[0].Y_end = TwBT;
	btn_TWEPERSON_To_buttons_continueANDnew_Form[0].sw_Link = Board_Form;
	btn_TWEPERSON_To_buttons_continueANDnew_Form[1].X_frist = TwLB;
	btn_TWEPERSON_To_buttons_continueANDnew_Form[1].Y_frist = TwBT;
	btn_TWEPERSON_To_buttons_continueANDnew_Form[1].X_end = TwRB;
	btn_TWEPERSON_To_buttons_continueANDnew_Form[1].Y_end = TwBB;
	btn_TWEPERSON_To_buttons_continueANDnew_Form[1].sw_Link = Board_Form;

	struct button btn_Dice;
	btn_Dice.X_frist = DICE_L;
	btn_Dice.Y_frist = DICE_T;
	btn_Dice.X_end = DICE_R;
	btn_Dice.Y_end = DICE_B;
	btn_Dice.sw_Link = NULL;

	struct button btn_aboutUs;
	btn_aboutUs.X_frist = auL;
	btn_aboutUs.Y_frist = auT;
	btn_aboutUs.X_end = auR;
	btn_aboutUs.Y_end = auB;
	btn_aboutUs.sw_Link = AboutUs_Form;

	struct button btn_P1Nut1;
	btn_P1Nut1.X_frist = PP1N1_L;
	btn_P1Nut1.Y_frist = PP1N1_T;
	btn_P1Nut1.X_end = PP1N1_L + PPNW;
	btn_P1Nut1.Y_end = PP1N1_T + PPNW;
	btn_P1Nut1.sw_Link = NULL;

	struct button btn_P1Nut2;
	btn_P1Nut2.X_frist = PP1N2_L;
	btn_P1Nut2.Y_frist = PP1N2_T;
	btn_P1Nut2.X_end = PP1N2_L + PPNW;
	btn_P1Nut2.Y_end = PP1N2_T + PPNW;
	btn_P1Nut2.sw_Link = NULL;

	struct button btn_P2Nut1;
	btn_P2Nut1.X_frist = PP2N1_L;
	btn_P2Nut1.Y_frist = PP2N1_T;
	btn_P2Nut1.X_end = PP2N1_L + PPNW;
	btn_P2Nut1.Y_end = PP2N1_T + PPNW;
	btn_P2Nut1.sw_Link = NULL;

	struct button btn_P2Nut2;
	btn_P2Nut2.X_frist = PP2N2_L;
	btn_P2Nut2.Y_frist = PP2N2_T;
	btn_P2Nut2.X_end = PP2N2_L + PPNW;
	btn_P2Nut2.Y_end = PP2N2_T + PPNW;
	btn_P2Nut2.sw_Link = NULL;
	//Edit!!!
	struct button btn_closeDoor_card_p1;
	btn_closeDoor_card_p1.X_frist = cdcp1_L;
	btn_closeDoor_card_p1.Y_frist = cdcp1_T;
	btn_closeDoor_card_p1.X_end = cdcp1_R;
	btn_closeDoor_card_p1.Y_end = cdcp1_B;
	btn_closeDoor_card_p1.sw_Link = Board_Form;

	struct button btn_coef_card_p1;
	btn_coef_card_p1.X_frist = zcp1_L;
	btn_coef_card_p1.Y_frist = zcp1_T;
	btn_coef_card_p1.X_end = zcp1_R;
	btn_coef_card_p1.Y_end = zcp1_B;
	btn_coef_card_p1.sw_Link = Board_Form;

	struct button btn_limit_card_p1;
	btn_limit_card_p1.X_frist = lcp1_L;
	btn_limit_card_p1.Y_frist = lcp1_T;
	btn_limit_card_p1.X_end = lcp1_R;
	btn_limit_card_p1.Y_end = lcp1_B;
	btn_limit_card_p1.sw_Link = Board_Form;

	struct button btn_diceAgain_card_p1;
	btn_diceAgain_card_p1.X_frist = dcp1_L;
	btn_diceAgain_card_p1.Y_frist = dcp1_T;
	btn_diceAgain_card_p1.X_end = dcp1_R;
	btn_diceAgain_card_p1.Y_end = dcp1_B;
	btn_diceAgain_card_p1.sw_Link = Board_Form;
	//p2
	struct button btn_closeDoor_card_p2;
	btn_closeDoor_card_p2.X_frist = cdcp2_L;
	btn_closeDoor_card_p2.Y_frist = cdcp2_T;
	btn_closeDoor_card_p2.X_end = cdcp2_R;
	btn_closeDoor_card_p2.Y_end = cdcp2_B;
	btn_closeDoor_card_p2.sw_Link = Board_Form;

	struct button btn_coef_card_p2;
	btn_coef_card_p2.X_frist = zcp2_L;
	btn_coef_card_p2.Y_frist = zcp2_T;
	btn_coef_card_p2.X_end = zcp2_R;
	btn_coef_card_p2.Y_end = zcp2_B;
	btn_coef_card_p2.sw_Link = Board_Form;

	struct button btn_limit_card_p2;
	btn_limit_card_p2.X_frist = lcp2_L;
	btn_limit_card_p2.Y_frist = lcp2_T;
	btn_limit_card_p2.X_end = lcp2_R;
	btn_limit_card_p2.Y_end = lcp2_B;
	btn_limit_card_p2.sw_Link = Board_Form;

	struct button btn_diceAgain_card_p2;
	btn_diceAgain_card_p2.X_frist = dcp2_L;
	btn_diceAgain_card_p2.Y_frist = dcp2_T;
	btn_diceAgain_card_p2.X_end = dcp2_R;
	btn_diceAgain_card_p2.Y_end = dcp2_B;
	btn_diceAgain_card_p2.sw_Link = Board_Form;

	struct button btn_MenuInTheBoard;
	btn_MenuInTheBoard.X_frist = PMBI_L;
	btn_MenuInTheBoard.Y_frist = PMBI_T;
	btn_MenuInTheBoard.X_end = PMBI_L + PPNW;
	btn_MenuInTheBoard.Y_end = PMBI_T + PPNW;
	btn_MenuInTheBoard.sw_Link = NULL;

	//MenuMassage
	// struct button btn_YesInMenuMessageInTheBoard;
	// btn_YesInMenuMessageInTheBoard.X_frist = PYIMMIB_L;
	// btn_YesInMenuMessageInTheBoard.Y_frist = PYIMMIB_T;
	// btn_YesInMenuMessageInTheBoard.X_end = PYIMMIB_R;
	// btn_YesInMenuMessageInTheBoard.Y_end = PYIMMIB_B;
	// btn_YesInMenuMessageInTheBoard.sw_Link = NULL;
	//---------------------------
	struct NUT P1Nut1;
	P1Nut1.x = PP1N1_L;
	P1Nut1.y = PP1N1_T;

	struct NUT P1Nut2;
	P1Nut2.x = PP1N2_L;
	P1Nut2.y = PP1N2_T;

	struct NUT P2Nut1;
	P2Nut1.x = PP2N1_L;
	P2Nut1.y = PP2N1_T;

	struct NUT P2Nut2;
	P2Nut2.x = PP2N2_L;

	P2Nut2.y = PP2N2_T;
#pragma endregion
	//Objects
#pragma region Images of Board Form
	ALLEGRO_EVENT event;

	ALLEGRO_BITMAP* Board_PIC = al_load_bitmap("Images/MIMBOARD.png");

	ALLEGRO_BITMAP* Dice_PIC[6];
	Dice_PIC[DiceP3] = al_load_bitmap("Images/Dice/TAS_puls3.png");
	Dice_PIC[DiceP2] = al_load_bitmap("Images/Dice/TAS_puls2.png");
	Dice_PIC[DiceP1] = al_load_bitmap("Images/Dice/TAS_puls1.png");
	Dice_PIC[DiceM3] = al_load_bitmap("Images/Dice/TAS_mine3.png");
	Dice_PIC[DiceM2] = al_load_bitmap("Images/Dice/TAS_mine2.png");
	Dice_PIC[DiceM1] = al_load_bitmap("Images/Dice/TAS_mine1.png");

	ALLEGRO_BITMAP* NutsP1_PIC[2];
	P1Nut1.picture = al_load_bitmap("Images/MOHRE1.png");
	P1Nut2.picture = al_load_bitmap("Images/MOHRE1.png");

	ALLEGRO_BITMAP* NutsP2_PIC[2];
	P2Nut1.picture = al_load_bitmap("Images/MOHRE2.png");
	P2Nut2.picture = al_load_bitmap("Images/MOHRE2.png");

	ALLEGRO_BITMAP* lucky_CardP1_PIC[4];
	lucky_CardP1_PIC[Place1] = al_load_bitmap("Images/Cards/closeDoor_cart_p1.png");
	lucky_CardP1_PIC[Place2] = al_load_bitmap("Images/Cards/zarib_cart_p1.png");
	lucky_CardP1_PIC[Place3] = al_load_bitmap("Images/Cards/limit_cart_p1.png");
	lucky_CardP1_PIC[Place4] = al_load_bitmap("Images/Cards/diceagain_cart_p1.png");

	ALLEGRO_BITMAP* lucky_CardP2_PIC[4];
	lucky_CardP2_PIC[Place1] = al_load_bitmap("Images/Cards/closeDoor_cart_p2.png");
	lucky_CardP2_PIC[Place2] = al_load_bitmap("Images/Cards/zarib_cart_p2.png");
	lucky_CardP2_PIC[Place3] = al_load_bitmap("Images/Cards/limit_cart_p2.png");
	lucky_CardP2_PIC[Place4] = al_load_bitmap("Images/Cards/diceagain_cart_p2.png");

	ALLEGRO_BITMAP* Place_Start_Nuts_P1[2];
	Place_Start_Nuts_P1[Place1] = al_load_bitmap("Images/BLOCK_player1.png");
	Place_Start_Nuts_P1[Place2] = al_load_bitmap("Images/BLOCK_player1.png");

	ALLEGRO_BITMAP* Place_Start_Nuts_P2[2];
	Place_Start_Nuts_P2[Place1] = al_load_bitmap("Images/BLOCK_player2.png");
	Place_Start_Nuts_P2[Place2] = al_load_bitmap("Images/BLOCK_player2.png");

	//ALLEGRO_BITMAP* ProgressP1 = al_load_bitmap("Images/MIMBOARD.png");
	//ALLEGRO_BITMAP* ProgressP2 = al_load_bitmap("Images/MIMBOARD.png");

	ALLEGRO_BITMAP* RefreshIcon = al_load_bitmap("Images/RESTART.png");

	ALLEGRO_BITMAP* GuideIcon = al_load_bitmap("Images/Qestion.png");

	ALLEGRO_BITMAP* Menu_InTheBoard_Icon = al_load_bitmap("Images/Menuintheboard.png");

	ALLEGRO_BITMAP* MenuFramePic = al_load_bitmap("Images/BLOCK_STOP_menu.png");

	ALLEGRO_BITMAP* CaractersP1_PIC = al_load_bitmap("Images/Caracters/superMan.png");

	ALLEGRO_BITMAP* CaractersP2_PIC = al_load_bitmap("Images/Caracters/strongMan.png");

	//Frist
	ALLEGRO_BITMAP* FristMenu_Form_PIC = al_load_bitmap("Images/startMenu/Form.png");
	ALLEGRO_BITMAP* startgame_PIC = al_load_bitmap("Images/startgame.png");
	ALLEGRO_BITMAP* Formcontinue_PIC = al_load_bitmap("Images/Form_continue.png");
	ALLEGRO_BITMAP* btn_menu_masage = al_load_bitmap("Images/massage_menu.png");

	//ALLEGRO_BITMAP* MenuInTheBoard_PIC = al_load_bitmap("Images/MessageMenu.png");

	ALLEGRO_BITMAP* Dice_PIC_VAR = Dice_PIC[DiceP3];

	ALLEGRO_COLOR NutActiveColorP2 = al_map_rgb(145, 216, 247);
	ALLEGRO_COLOR NutActiveColorP1 = al_map_rgb(247, 173, 175);


#pragma endregion


	//current Window
	al_start_timer(timer);
	while (1)
	{
		al_wait_for_event(queue, &event);
		switch (event.type)
		{
		case ALLEGRO_EVENT_TIMER:
			sw = true;
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			done = true;
			break;
		}
		if (done)break;

		if (sw && al_is_event_queue_empty(queue))
		{
			//Program
			switch (pages_sw)
			{
			case StartGame:
				al_clear_to_color(al_map_rgb(240, 240, 240));
				al_draw_bitmap(startgame_PIC, 0, 0, 0);
				if (count_startgame == 300)
				{
					pages_sw = Form_continue;
				}
				count_startgame++;
				break;
			case Form_continue:
				for (int i = 0; i < load_percent && load_percent <= 302; i++)
				{
					al_draw_filled_circle(500.4 + i, 692.6, 10.5, al_map_rgb(255, 255, 255));

				}
				if (load_percent == 302)pages_sw = FristMenu;
				load_percent++;
				break;
			case FristMenu:
#pragma region Codes
				if (Permission_change_mouse)
				{
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
					Permission_change_mouse = false;
				}
				al_draw_bitmap(FristMenu_Form_PIC, 0, 0, 0);
				al_get_mouse_state(&mouseState);
				//click in the buttons
				if (is_Position_btn(mouseState))al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				if (sw_btn(&btn_Guide, &mouseState) && mouseState.buttons == 1)
				{
					pages_sw = Board_Form;
					Permission_change_mouse = true;
				}
				if (sw_btn(&btn_ONEPERSON_To_buttons_continueANDnew_Form[0], &mouseState) && mouseState.buttons == 1)
				{
					//pages_sw = Board_Form;
					//Permission_change_mouse = true;
				}
				if (sw_btn(&btn_ONEPERSON_To_buttons_continueANDnew_Form[1], &mouseState) && mouseState.buttons == 1)
				{
					//pages_sw = Board_Form;
					//Permission_change_mouse = true;

				}
				if (sw_btn(&btn_TWEPERSON_To_buttons_continueANDnew_Form[0], &mouseState) && mouseState.buttons == 1)
				{
					pages_sw = Board_Form;
					Permission_change_mouse = true;
					CardPlacesRand(ArrayCardsPlace);
					CarridorPlacesRand(ArrayCarridorsPlace);
					//print in console information of cards and Carridors
					for (int i = 0; i < 9; i++) printf("%d\n", ArrayCardsPlace[i] + 1);
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 2; j++)
						{
							printf("%d ", ArrayCarridorsPlace[i][j] + 1);
						}
						printf("\n");
					}
				}
				if (sw_btn(&btn_TWEPERSON_To_buttons_continueANDnew_Form[1], &mouseState) && mouseState.buttons == 1)
				{
					pages_sw = Board_Form;
					Permission_change_mouse = true;
					CardPlacesRand(ArrayCardsPlace);
					CarridorPlacesRand(ArrayCarridorsPlace);
					//print in console information of cards and Carridors
					for (int i = 0; i < 9; i++) printf("%d\n", ArrayCardsPlace[i] + 1);
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 2; j++)
						{
							printf("%d ", ArrayCarridorsPlace[i][j] + 1);
						}
						printf("\n");
					}

				}

				if (sw_btn(&btn_aboutUs, &mouseState))
				{
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
					if (mouseState.buttons == 1)
					{
						exit(2);
					}
				}

#pragma endregion
				break;
			case buttons_continueANDnew_Form:
				break;
			case Template_Form:
				break;
			case Guide_Form:
				break;
			case AboutUs_Form:
				break;
			case Setting_Form:
				break;
			case Board_Form:
#pragma region codes
				if (Permission_change_mouse)
				{
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
					Permission_change_mouse = false;
				}
				al_get_mouse_state(&mouseState);
				al_clear_to_color(al_map_rgb(240, 240, 240));
				//Board & cards------------------------------
				al_get_mouse_state(&mouseState);
				al_draw_bitmap(lucky_CardP1_PIC[Place1], 227, 341, 0);
				al_draw_bitmap(lucky_CardP1_PIC[Place2], 227, 431, 0);
				al_draw_bitmap(lucky_CardP1_PIC[Place3], 227, 520, 0);
				al_draw_bitmap(lucky_CardP1_PIC[Place4], 227, 610, 0);
				if (Tik_Dice)
					if (player_Turn == P1)
						if (sw_btn(&btn_diceAgain_card_p1, &mouseState))
						{
							if (al_mouse_button_down(&mouseState, 1) && !one_click_btn_DICEAGAIN_CARD_p1)
							{
								one_click_btn_DICEAGAIN_CARD_p1 = true;
								printf("cardAgain1%\n");
								if (CardsP1[DICEAGAIN])
								{
									printf("dice Again:%d\n", CardsP1[DICEAGAIN]-1);
									CardsP1[DICEAGAIN]--;
									User_operation = CLICKDICE;
								}
							}
							else if (!al_mouse_button_down(&mouseState, 1)) one_click_btn_DICEAGAIN_CARD_p1 = false;
						}

				al_draw_bitmap(lucky_CardP2_PIC[Place1], 949, 121, 0);
				al_draw_bitmap(lucky_CardP2_PIC[Place2], 949, 210, 0);
				al_draw_bitmap(lucky_CardP2_PIC[Place3], 949, 300, 0);
				al_draw_bitmap(lucky_CardP2_PIC[Place4], 949, 390, 0);
				if (Tik_Dice)
					if (player_Turn == P2)
						if (sw_btn(&btn_diceAgain_card_p2, &mouseState))
						{
							if (al_mouse_button_down(&mouseState, 1) && !one_click_btn_DICEAGAIN_CARD_p2)
							{
								one_click_btn_DICEAGAIN_CARD_p2 = true;
								printf("cardAgain2%\n");
								if (CardsP2[DICEAGAIN])
								{
									printf("dice Again:%d\n", CardsP2[DICEAGAIN]-1);
									CardsP2[DICEAGAIN]--;
									User_operation = CLICKDICE;
								}
							}
							else if (!al_mouse_button_down(&mouseState, 1)) one_click_btn_DICEAGAIN_CARD_p2 = false;
						}
				al_draw_bitmap(Place_Start_Nuts_P1[Place1], 350, 692, 0);
				al_draw_bitmap(Place_Start_Nuts_P1[Place2], 455, 692, 0);
				al_draw_bitmap(Place_Start_Nuts_P2[Place1], 850, 80, 0);
				al_draw_bitmap(Place_Start_Nuts_P2[Place2], 745, 80, 0);

				al_draw_bitmap(Board_PIC, 350, 100, 0);
				//-----------------------------------------

				//Dice-------------------------------------
				al_get_mouse_state(&mouseState);
				al_draw_bitmap(Dice_PIC_VAR, DICE_L, DICE_T, 0);
				if (sw_btn(&btn_Dice, &mouseState))
				{
					if (Tik_Player)
					{
						al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
						if (!sw_btnDown) if (al_mouse_button_down(&mouseState, 1))
						{
							printf("hh\n");
							User_operation = CLICKDICE;
							Tik_Dice = true;
							Tik_Player = false;
						}
						if (!al_mouse_button_down(&mouseState, 1)) sw_btnDown = false;
					}
				}
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
				//-----------------------------------------

				//Nuts-------------------------------------
				if (IsLimitP1 == 0)if (player_Turn == P1)al_draw_circle(P1Nut1.x + PPNW / 2 - 1, P1Nut1.y + PPNW / 2, PPNW / 2, NutActiveColorP1, 5);
				al_draw_bitmap(P1Nut1.picture, P1Nut1.x, P1Nut1.y, 0);

				if (IsLimitP1 == 0)if (player_Turn == P1)al_draw_circle(P1Nut2.x + PPNW / 2 - 1, P1Nut2.y + PPNW / 2, PPNW / 2, NutActiveColorP1, 5);
				al_draw_bitmap(P1Nut2.picture, P1Nut2.x, P1Nut2.y, 0);

				if (IsLimitP2 == 0)if (player_Turn == P2)al_draw_circle(P2Nut1.x + PPNW / 2 - 1, P2Nut1.y + PPNW / 2, PPNW / 2, NutActiveColorP2, 5);
				al_draw_bitmap(P2Nut1.picture, P2Nut1.x, P2Nut1.y, 0);

				if (IsLimitP2 == 0)if (player_Turn == P2)al_draw_circle(P2Nut2.x + PPNW / 2 - 1, P2Nut2.y + PPNW / 2, PPNW / 2, NutActiveColorP2, 5);
				al_draw_bitmap(P2Nut2.picture, P2Nut2.x, P2Nut2.y, 0);
				if (Tik_Dice)
				{
					al_get_mouse_state(&mouseState);
					if (sw_btn(&btn_P1Nut1, &mouseState))
					{
						if (IsLimitP1 == 0)
							if (P1N1_IsLive)
								if (al_mouse_button_down(&mouseState, 1))
								{
									User_operation = CLICKNUT1_P1;
									Tik_Nut = true;

									if (player_Turn == P1)
									{
										Tik_Dice = false;
										Tik_Player = true;
									}
								}
					}
					else if (sw_btn(&btn_P1Nut2, &mouseState))
					{
						if (IsLimitP1 == 0)
							if (P1N2_IsLive)
								if (al_mouse_button_down(&mouseState, 1))
								{
									User_operation = CLICKNUT2_P1;
									Tik_Nut = true;

									if (player_Turn == P1)
									{
										Tik_Dice = false;
										Tik_Player = true;
									}
								}
					}
					else if (sw_btn(&btn_P2Nut1, &mouseState))
					{
						if (IsLimitP2 == 0)
							if (P2N1_IsLive)
								if (al_mouse_button_down(&mouseState, 1))
								{
									User_operation = CLICKNUT1_P2;
									Tik_Nut = true;
									if (player_Turn == P2)
									{
										Tik_Dice = false;
										Tik_Player = true;
									}
								}
					}
					else if (sw_btn(&btn_P2Nut2, &mouseState))
					{
						if (IsLimitP2 == 0)
							if (P2N2_IsLive)
								if (al_mouse_button_down(&mouseState, 1))
								{
									User_operation = CLICKNUT2_P2;
									Tik_Nut = true;
									if (player_Turn == P2)
									{
										Tik_Dice = false;
										Tik_Player = true;
									}
								}
					}
				}
				//-----------------------------------------

				//Caracters--------------------------------
				al_draw_bitmap(CaractersP1_PIC, 10, 290, 0);
				al_draw_bitmap(CaractersP2_PIC, 1090, 100, 0);
				//-----------------------------------------

				//Menu Frame-------------------------------
				al_draw_bitmap(MenuFramePic, 25, -12, 0);
				al_draw_bitmap(Menu_InTheBoard_Icon, 35, -5, 0);

				al_get_mouse_state(&mouseState);

				//idea of menu Message
				//******************************************************
				/*if (sw_btn(&btn_MenuInTheBoard, &mouseState))
				{
					if (al_mouse_button_down(&mouseState, 1))
					{
						printf("Hello\n");
						sw_Show_MessageBoxMenu = true;
					}
				}
				if (sw_Show_MessageBoxMenu)
				{
					printf("No\n");
					al_draw_bitmap(MenuInTheBoard_PIC, 0, 0, 0);
					al_flip_display();
					while (1)
					{
						al_wait_for_event(queue, &event);
						al_get_mouse_state(&mouseState);
						if (sw_btn(&btn_YesInMenuMessageInTheBoard, &mouseState))
						{
							if (al_mouse_button_down(&mouseState, 1))
							{
								sw_Show_MessageBoxMenu = false;
								break;
							}
						}
					}
				}*/
				//********************************************************
				al_draw_bitmap(RefreshIcon, 105, -5, 0);
				al_draw_bitmap(GuideIcon, 170, -5, 0);
				//-----------------------------------------
#pragma region LOGIC
				switch (player_Turn)
				{
				case P1:
					switch (User_operation)
					{
					case CLICKDICE:
						sw_btnDown = true;
						DiceVar = DiceRand();
						Dice_PIC_VAR = Dice_PIC[DiceVar];
						ConvertToDiceMIM(&DiceVar);
						User_operation = -1;
						break;
					case CLICKCARD_doorclosed:
						break;
					case CLICKCARD_coef:
						break;
					case CLICKCARD_limit:
						break;
					case CLICKCARD_diceagain:
						break;
					case CLICKNUT1_P1:
						printf("yesP1N1\n\n");
						if (Tik_Nut == true)
						{
							if ((Player1[0] + DiceVar) > -1 && (Player1[0] + DiceVar) < 81)//check for Being to period
							{
								//1-moving
								Player1[0] += DiceVar;
								MoveGraphic(Player1[0], &(P1Nut1.x), &(P1Nut1.y));
								//---------------------------------------

								//2-Hitting
								if (Player1[0] == Player2[0]) {
									Player2[0] = 80;
									P2Nut1.x = PP2N1_L;
									P2Nut1.y = PP2N1_T;

									btn_P2Nut1.X_frist = PP2N1_L;
									btn_P2Nut1.Y_frist = PP2N1_T;
									btn_P2Nut1.X_end = PP2N1_L + PPNW;
									btn_P2Nut1.Y_end = PP2N1_T + PPNW;
								}
								if (Player1[0] == Player2[1]) {
									Player2[1] = 80;
									P2Nut1.x = PP2N2_L;
									P2Nut1.y = PP2N2_T;

									btn_P2Nut2.X_frist = PP2N2_L;
									btn_P2Nut2.Y_frist = PP2N2_T;
									btn_P2Nut2.X_end = PP2N2_L + PPNW;
									btn_P2Nut2.Y_end = PP2N2_T + PPNW;
								}
								//--------------------------------

								//3-Become add a Lucky Card
								if (IsLuckyCardPlace(Player1[0], ArrayCardsPlace))
								{
									CardChoosed = CardRand();
									CardsP1[CardChoosed]++;
									switch (CardChoosed)
									{
									case DOORCLOSED:
										printf("a DOOR_CLOSED card added.\n");

										break;
									case COEF:
										printf("a COEF card added.\n");
										break;
									case LIMIT:
										printf("a LIMIT card added.\n");
										break;
									case DICEAGAIN:
										printf("a DICE_AGAIN card added.\n");

										break;
									}
									for (int i = 0; i < 4; i++)
									{
										printf("%d ", CardsP1[i]);
									}
								}
								//--------------------------------------

								//4-move with carridors
								bool IsCarridor = false;
								if (IsCarridorPlace(&Player1[0], ArrayCarridorsPlace))
								{
									printf("? %d", Player1[0]);
									IsCarridor = true;

									//2-Hitting
									if (Player1[0] == Player2[0]) {
										Player2[0] = 80;
										P2Nut1.x = PP2N1_L;
										P2Nut1.y = PP2N1_T;

										btn_P2Nut1.X_frist = PP2N1_L;
										btn_P2Nut1.Y_frist = PP2N1_T;
										btn_P2Nut1.X_end = PP2N1_L + PPNW;
										btn_P2Nut1.Y_end = PP2N1_T + PPNW;
									}
									if (Player1[0] == Player2[1]) {
										Player2[1] = 80;
										P2Nut1.x = PP2N2_L;
										P2Nut1.y = PP2N2_T;

										btn_P2Nut2.X_frist = PP2N2_L;
										btn_P2Nut2.Y_frist = PP2N2_T;
										btn_P2Nut2.X_end = PP2N2_L + PPNW;
										btn_P2Nut2.Y_end = PP2N2_T + PPNW;
									}
									//--------------------------------

									//3-Become add a Lucky Card
									if (IsLuckyCardPlace(Player1[0], ArrayCardsPlace))
									{
										CardChoosed = CardRand();
										CardsP1[CardChoosed]++;
										switch (CardChoosed)
										{
										case DOORCLOSED:
											printf("a DOOR_CLOSED card added.\n");

											break;
										case COEF:
											printf("a COEF card added.\n");
											break;
										case LIMIT:
											printf("a LIMIT card added.\n");
											break;
										case DICEAGAIN:
											printf("a DICE_AGAIN card added.\n");

											break;
										}
										for (int i = 0; i < 4; i++)
										{
											printf("%d ", CardsP1[i]);
										}
									}
									//--------------------------------------

								}
								if (IsCarridor) MoveGraphic(Player1[0], &(P1Nut1.x), &(P1Nut1.y));
								//-------------------------------

								btn_P1Nut1.X_frist = P1Nut1.x;
								btn_P1Nut1.Y_frist = P1Nut1.y;
								btn_P1Nut1.X_end = P1Nut1.x + PPNW;
								btn_P1Nut1.Y_end = P1Nut1.y + PPNW;
							}
							User_operation = -1;
							player_Turn = P2;


						}
						break;
					case CLICKNUT2_P1:
						if (Tik_Nut == true)
						{
							printf("yesP1N2\n\n");
							if ((Player1[1] + DiceVar) > -1 && (Player1[1] + DiceVar) < 81)//check for Being to period
							{
								//1-moving
								Player1[1] += DiceVar;
								MoveGraphic(Player1[1], &(P1Nut2.x), &(P1Nut2.y));
								//-----------------------------------

								//2-Hitting
								if (Player1[1] == Player2[0]) {
									Player2[0] = 80;
									P2Nut1.x = PP2N1_L;
									P2Nut1.y = PP2N1_T;

									btn_P2Nut1.X_frist = PP2N1_L;
									btn_P2Nut1.Y_frist = PP2N1_T;
									btn_P2Nut1.X_end = PP2N1_L + PPNW;
									btn_P2Nut1.Y_end = PP2N1_T + PPNW;
								}
								if (Player1[1] == Player2[1]) {
									Player2[1] = 80;
									P2Nut2.x = PP2N2_L;
									P2Nut2.y = PP2N2_T;

									btn_P2Nut2.X_frist = PP2N2_L;
									btn_P2Nut2.Y_frist = PP2N2_T;
									btn_P2Nut2.X_end = PP2N2_L + PPNW;
									btn_P2Nut2.Y_end = PP2N2_T + PPNW;
								}
								//--------------------------------

								//3-Become add a Lucky Card
								if (IsLuckyCardPlace(Player1[1], ArrayCardsPlace))
								{
									CardChoosed = CardRand();
									CardsP1[CardChoosed]++;
									switch (CardChoosed)
									{
									case DOORCLOSED:
										printf("a DOOR_CLOSED card added.\n");
										break;
									case COEF:
										printf("a COEF card added.\n");
										break;
									case LIMIT:
										printf("a LIMIT card added.\n");
										break;
									case DICEAGAIN:
										printf("a DICE_AGAIN card added.\n");
										break;
									}
									for (int i = 0; i < 4; i++)
									{
										printf("%d ", CardsP1[i]);
									}
								}
								//--------------------------------------

								//4-move with carridors
								bool IsCarridor = false;
								if (IsCarridorPlace(&Player1[1], ArrayCarridorsPlace))
								{
									printf("? %d", Player1[1]);
									IsCarridor = true;

									//2-Hitting
									if (Player1[1] == Player2[0]) {
										Player2[0] = 80;
										P2Nut1.x = PP2N1_L;
										P2Nut1.y = PP2N1_T;

										btn_P2Nut1.X_frist = PP2N1_L;
										btn_P2Nut1.Y_frist = PP2N1_T;
										btn_P2Nut1.X_end = PP2N1_L + PPNW;
										btn_P2Nut1.Y_end = PP2N1_T + PPNW;
									}
									if (Player1[1] == Player2[1]) {
										Player2[1] = 80;
										P2Nut2.x = PP2N2_L;
										P2Nut2.y = PP2N2_T;

										btn_P2Nut2.X_frist = PP2N2_L;
										btn_P2Nut2.Y_frist = PP2N2_T;
										btn_P2Nut2.X_end = PP2N2_L + PPNW;
										btn_P2Nut2.Y_end = PP2N2_T + PPNW;
									}
									//--------------------------------

									//3-Become add a Lucky Card
									if (IsLuckyCardPlace(Player1[1], ArrayCardsPlace))
									{
										CardChoosed = CardRand();
										CardsP1[CardChoosed]++;
										switch (CardChoosed)
										{
										case DOORCLOSED:
											printf("a DOOR_CLOSED card added.\n");
											break;
										case COEF:
											printf("a COEF card added.\n");
											break;
										case LIMIT:
											printf("a LIMIT card added.\n");
											break;
										case DICEAGAIN:
											printf("a DICE_AGAIN card added.\n");
											break;
										}
										for (int i = 0; i < 4; i++)
										{
											printf("%d ", CardsP1[i]);
										}
									}
									//--------------------------------------
								}
								if (IsCarridor) MoveGraphic(Player1[1], &(P1Nut2.x), &(P1Nut2.y));								//-------------------------------
								//-------------------------------------------
								btn_P1Nut2.X_frist = P1Nut2.x;
								btn_P1Nut2.Y_frist = P1Nut2.y;
								btn_P1Nut2.X_end = P1Nut2.x + PPNW;
								btn_P1Nut2.Y_end = P1Nut2.y + PPNW;

							}
							User_operation = -1;
							player_Turn = P2;

						}
						break;
					case CLICKNUT1_ENEMY:
						break;
					case CLICKNUT2_ENEMY:
						break;
					default:
						break;
					}

					break;
				case P2:
					switch (User_operation)
					{
					case CLICKDICE:
						sw_btnDown = true;
						DiceVar = DiceRand();
						Dice_PIC_VAR = Dice_PIC[DiceVar];
						ConvertToDiceMIM(&DiceVar);

						User_operation = -1;
						break;
					case CLICKCARD_doorclosed:
						break;
					case CLICKCARD_coef:
						break;
					case CLICKCARD_limit:
						break;
					case CLICKCARD_diceagain:
						break;
					case CLICKNUT1_P2:
						if (Tik_Nut == true)
						{
							printf("yesP2N1\n\n");

							if ((Player2[0] + DiceVar) > -1 && (Player2[0] + DiceVar) < 81)//check for Being to period
							{
								//1-moving
								Player2[0] += DiceVar;
								MoveGraphic(Player2[0], &(P2Nut1.x), &(P2Nut1.y));
								//------------------------------------

								//2-Hitting
								if (Player2[0] == Player1[0]) {
									Player1[0] = 0;
									P1Nut1.x = PP1N1_L;
									P1Nut1.y = PP1N1_T;

									btn_P1Nut1.X_frist = PP1N1_L;
									btn_P1Nut1.Y_frist = PP1N1_T;
									btn_P1Nut1.X_end = PP1N1_L + PPNW;
									btn_P1Nut1.Y_end = PP1N1_T + PPNW;
								}
								if (Player2[0] == Player1[1]) {
									Player1[1] = 0;
									P1Nut2.x = PP1N2_L;
									P1Nut2.y = PP1N2_T;

									btn_P1Nut2.X_frist = PP1N2_L;
									btn_P1Nut2.Y_frist = PP1N2_T;
									btn_P1Nut2.X_end = PP1N2_L + PPNW;
									btn_P1Nut2.Y_end = PP1N2_T + PPNW;
								}
								//--------------------------------

								//3-Become add a Lucky Card
								if (IsLuckyCardPlace(Player2[0], ArrayCardsPlace))
								{
									CardChoosed = CardRand();
									CardsP2[CardChoosed]++;
									switch (CardChoosed)
									{
									case DOORCLOSED:
										printf("a DOOR_CLOSED card added.\n");
										break;
									case COEF:
										printf("a COEF card added.\n");
										break;
									case LIMIT:
										printf("a LIMIT card added.\n");
										break;
									case DICEAGAIN:
										printf("a DICE_AGAIN card added.\n");
										break;
									}
									for (int i = 0; i < 4; i++)
									{
										printf("%d ", CardsP2[i]);
									}
								}
								//--------------------------------------

								//4-move with carridors
								bool IsCarridor = false;
								if (IsCarridorPlace(&Player2[0], ArrayCarridorsPlace))
								{
									printf("? %d", Player2[0]);
									IsCarridor = true;

									//2-Hitting
									if (Player2[0] == Player1[0]) {
										Player1[0] = 0;
										P1Nut1.x = PP1N1_L;
										P1Nut1.y = PP1N1_T;

										btn_P1Nut1.X_frist = PP1N1_L;
										btn_P1Nut1.Y_frist = PP1N1_T;
										btn_P1Nut1.X_end = PP1N1_L + PPNW;
										btn_P1Nut1.Y_end = PP1N1_T + PPNW;
									}
									if (Player2[0] == Player1[1]) {
										Player1[1] = 0;
										P1Nut2.x = PP1N2_L;
										P1Nut2.y = PP1N2_T;

										btn_P1Nut2.X_frist = PP1N2_L;
										btn_P1Nut2.Y_frist = PP1N2_T;
										btn_P1Nut2.X_end = PP1N2_L + PPNW;
										btn_P1Nut2.Y_end = PP1N2_T + PPNW;
									}
									//--------------------------------

									//3-Become add a Lucky Card
									if (IsLuckyCardPlace(Player2[0], ArrayCardsPlace))
									{
										CardChoosed = CardRand();
										CardsP2[CardChoosed]++;
										switch (CardChoosed)
										{
										case DOORCLOSED:
											printf("a DOOR_CLOSED card added.\n");
											break;
										case COEF:
											printf("a COEF card added.\n");
											break;
										case LIMIT:
											printf("a LIMIT card added.\n");
											break;
										case DICEAGAIN:
											printf("a DICE_AGAIN card added.\n");
											break;
										}
										for (int i = 0; i < 4; i++)
										{
											printf("%d ", CardsP2[i]);
										}
									}
									//--------------------------------------

								}
								//------------------------------------
								if (IsCarridor) MoveGraphic(Player2[0], &(P2Nut1.x), &(P2Nut1.y));
								btn_P2Nut1.X_frist = P2Nut1.x;
								btn_P2Nut1.Y_frist = P2Nut1.y;
								btn_P2Nut1.X_end = P2Nut1.x + PPNW;
								btn_P2Nut1.Y_end = P2Nut1.y + PPNW;
							}
							User_operation = -1;
							player_Turn = P1;
						}
						break;
					case CLICKNUT2_P2:
						if (Tik_Nut == true)
						{
							printf("yesP2N2\n\n");

							if ((Player2[1] + DiceVar) > -1 && (Player2[1] + DiceVar) < 81)//check for Being to period
							{
								//1-moving
								Player2[1] += DiceVar;
								MoveGraphic(Player2[1], &(P2Nut2.x), &(P2Nut2.y));
								//----------------------------------------------

								//2-Hitting
								if (Player2[1] == Player1[0]) {
									Player1[0] = 0;
									P1Nut1.x = PP1N1_L;
									P1Nut1.y = PP1N1_T;

									btn_P1Nut1.X_frist = PP1N1_L;
									btn_P1Nut1.Y_frist = PP1N1_T;
									btn_P1Nut1.X_end = PP1N1_L + PPNW;
									btn_P1Nut1.Y_end = PP1N1_T + PPNW;
								}
								if (Player2[1] == Player1[1]) {
									Player1[1] = 0;
									P1Nut2.x = PP1N2_L;
									P1Nut2.y = PP1N2_T;

									btn_P1Nut2.X_frist = PP1N2_L;
									btn_P1Nut2.Y_frist = PP1N2_T;
									btn_P1Nut2.X_end = PP1N2_L + PPNW;
									btn_P1Nut2.Y_end = PP1N2_T + PPNW;
								}
								//-----------------------------------------

								//3-Become add a Lucky Card
								if (IsLuckyCardPlace(Player2[1], ArrayCardsPlace))
								{
									CardChoosed = CardRand();
									CardsP2[CardChoosed]++;
									switch (CardChoosed)
									{
									case DOORCLOSED:
										printf("a DOOR_CLOSED card added.\n");
										break;
									case COEF:
										printf("a COEF card added.\n");
										break;
									case LIMIT:
										printf("a LIMIT card added.\n");
										break;
									case DICEAGAIN:
										printf("a DICE_AGAIN card added.\n");
										break;
									}
									for (int i = 0; i < 4; i++)
									{
										printf("%d ", CardsP2[i]);
									}
								}
								//--------------------------------------

								//4-move with carridors
								bool IsCarridor = false;
								if (IsCarridorPlace(&Player2[1], ArrayCarridorsPlace))
								{
									printf("? %d", Player2[1]);
									IsCarridor = true;
								}
								if (IsCarridor)
								{
									MoveGraphic(Player2[1], &(P2Nut2.x), &(P2Nut2.y));


									//2-Hitting
									if (Player2[1] == Player1[0]) {
										Player1[0] = 0;
										P1Nut1.x = PP1N1_L;
										P1Nut1.y = PP1N1_T;

										btn_P1Nut1.X_frist = PP1N1_L;
										btn_P1Nut1.Y_frist = PP1N1_T;
										btn_P1Nut1.X_end = PP1N1_L + PPNW;
										btn_P1Nut1.Y_end = PP1N1_T + PPNW;
									}
									if (Player2[1] == Player1[1]) {
										Player1[1] = 0;
										P1Nut2.x = PP1N2_L;
										P1Nut2.y = PP1N2_T;

										btn_P1Nut2.X_frist = PP1N2_L;
										btn_P1Nut2.Y_frist = PP1N2_T;
										btn_P1Nut2.X_end = PP1N2_L + PPNW;
										btn_P1Nut2.Y_end = PP1N2_T + PPNW;
									}
									//-----------------------------------------

									//3-Become add a Lucky Card
									if (IsLuckyCardPlace(Player2[1], ArrayCardsPlace))
									{
										CardChoosed = CardRand();
										CardsP2[CardChoosed]++;
										switch (CardChoosed)
										{
										case DOORCLOSED:
											printf("a DOOR_CLOSED card added.\n");
											break;
										case COEF:
											printf("a COEF card added.\n");
											break;
										case LIMIT:
											printf("a LIMIT card added.\n");
											break;
										case DICEAGAIN:
											printf("a DICE_AGAIN card added.\n");
											break;
										}
										for (int i = 0; i < 4; i++)
										{
											printf("%d ", CardsP2[i]);
										}
									}
									//--------------------------------------
								}
								//-------------------------------
								btn_P2Nut2.X_frist = P2Nut2.x;
								btn_P2Nut2.Y_frist = P2Nut2.y;
								btn_P2Nut2.X_end = P2Nut2.x + PPNW;
								btn_P2Nut2.Y_end = P2Nut2.y + PPNW;
							}
							User_operation = -1;
							player_Turn = P1;

						}
						break;
					case CLICKNUT1_ENEMY:
						break;
					case CLICKNUT2_ENEMY:
						break;
					default:
						break;
					}

					break;
				default:
					break;
				}

#pragma endregion

#pragma endregion
				if (Player1[0] == 40)
				{
					P1Nut1.x = 810;
					P1Nut1.y = 1300;
					P1N1_IsLive = false;
					Player1[0] = -1;
				}
				if (Player1[1] == 40)
				{
					P1Nut2.x = 810;
					P1Nut2.y = 1300;
					P1N2_IsLive = false;
					Player1[1] = -1;
				}
				if (Player2[0] == 40)
				{
					P2Nut1.x = 810;
					P2Nut1.y = 1300;
					P2N1_IsLive = false;
					Player2[0] = -1;
				}
				if (Player2[1] == 40)
				{
					P2Nut2.x = 810;
					P2Nut2.y = 1300;
					P2N2_IsLive = false;
					Player2[1] = -1;
				}
				break;
			case appointment_Form:
				break;
			case Choose_Card:
				break;
			default:
				break;
			}

			//Build Window-----------------------------
			al_flip_display();
			//-----------------------------------------
			sw = false;

		}
		if (Player1[0] == 40 && Player1[1] == 40)
		{
			printf("***************************   Hoora P1   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11");
		}
		else if (Player2[0] == 40 && Player2[1] == 40)
		{
			printf("***************************   Hoora P2   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11");
		}
	}
#pragma region Destroying
	al_destroy_display(disp);
	al_destroy_font(font);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);

	al_destroy_bitmap(CaractersP1_PIC);

	al_destroy_bitmap(CaractersP2_PIC);

	al_destroy_bitmap(NutsP1_PIC[NUT1]);
	al_destroy_bitmap(NutsP1_PIC[NUT2]);
	al_destroy_bitmap(NutsP2_PIC[NUT1]);
	al_destroy_bitmap(NutsP2_PIC[NUT2]);

	al_destroy_bitmap(Dice_PIC[DiceM1]);
	al_destroy_bitmap(Dice_PIC[DiceM2]);
	al_destroy_bitmap(Dice_PIC[DiceM3]);
	al_destroy_bitmap(Dice_PIC[DiceP1]);
	al_destroy_bitmap(Dice_PIC[DiceP2]);
	al_destroy_bitmap(Dice_PIC[DiceP3]);
	al_destroy_bitmap(Dice_PIC_VAR);

	al_destroy_bitmap(Place_Start_Nuts_P1[Place1]);
	al_destroy_bitmap(Place_Start_Nuts_P1[Place2]);
	al_destroy_bitmap(Place_Start_Nuts_P2[Place1]);
	al_destroy_bitmap(Place_Start_Nuts_P2[Place2]);

	al_destroy_bitmap(lucky_CardP1_PIC[Place1]);
	al_destroy_bitmap(lucky_CardP1_PIC[Place2]);
	al_destroy_bitmap(lucky_CardP1_PIC[Place3]);
	al_destroy_bitmap(lucky_CardP1_PIC[Place4]);
	al_destroy_bitmap(lucky_CardP2_PIC[Place1]);
	al_destroy_bitmap(lucky_CardP2_PIC[Place2]);
	al_destroy_bitmap(lucky_CardP2_PIC[Place3]);
	al_destroy_bitmap(lucky_CardP2_PIC[Place4]);

	al_destroy_bitmap(GuideIcon);
	al_destroy_bitmap(RefreshIcon);
	al_destroy_bitmap(Menu_InTheBoard_Icon);
	al_destroy_bitmap(MenuFramePic);

	al_destroy_bitmap(Board_PIC);

	al_destroy_bitmap(FristMenu_Form_PIC);
#pragma endregion
	return 0;
}