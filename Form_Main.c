#include "logic_Form.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
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
enum Number_of_Cards
{
	Y_NOCP1_DOORCLOSED = 141,
	Y_NOCP1_COEF = 231,
	Y_NOCP1_LIMIT = 321,
	Y_NOCP1_DICEAGAIN = 411,

	Y_NOCP2_DOORCLOSED = 350,
	Y_NOCP2_COEF = 440,
	Y_NOCP2_LIMIT = 530,
	Y_NOCP2_DICEAGAIN = 620,
};
enum Distances_for_Centering
{
	P1_SINGLE_DIGIT = 244,
	P1_DOUBLE_DIGIT = 237,
	P1_THREE_DIGIT = 228,

	P2_SINGLE_DIGIT = 1040,
	P2_DOUBLE_DIGIT = 1034,
	P2_THREE_DIGIT = 1022,
};
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
	PMBI_L = 42,
	PMBI_R = 94,
	PMBI_T = 0,
	PMBI_B = 57,
};
enum Position_RefreshInTheBoardIcon
{
	PRBI_L = 130,
	PRBI_R = 190,
	PRBI_T = -5,
	PRBI_B = 60,
};
enum Position_QuestionInTheBoardIcon
{
	PQBI_L = 200,
	PQBI_R = 255,
	PQBI_T = -5,
	PQBI_B = 60,
};
enum Position_Save_Icon
{
	PSI_L = 240,
	PSI_T = 0,
	PSI_R = 308,
	PSI_B = 63,
};
enum Position_YesInMenuMessageInTheBoard
{
	PYIMMIB_L = 673,
	PYIMMIB_T = 515,
	PYIMMIB_R = 882,
	PYIMMIB_B = 580,
};
enum Position_NoInMenuMessageInTheBoard
{
	PNIMMIB_L = 442,
	PNIMMIB_T = 517,
	PNIMMIB_R = 617,
	PNIMMIB_B = 603,
};
enum Position_CancelInMessagesICON
{
	PCIMI_L = 625,
	PCIMI_T = 185,
	PCIMI_R = 704,
	PCIMI_B = 253,

};
enum Position_CANCELbtn_NoticeToCarridor
{
	PCbNC_L = 867,
	PCbNC_T = 746,
	PCbNC_R = 1041,
	PCbNC_B = 791,
};
enum Position_OKbtn_NoticeToCarridor
{
	PObNC_L = 1072,
	PObNC_T = 746,
	PObNC_R = 1240,
	PObNC_B = 791,
};

enum coef_card_p1
{
	zcp1_L = 225,
	zcp1_R = 350,
	zcp1_T = 124,
	zcp1_B = 194,
};
enum diceAgain_card_p1
{
	dcp1_L = 225,
	dcp1_R = 350,
	dcp1_T = 214,
	dcp1_B = 284,
};
enum limit_card_p1
{
	lcp1_L = 225,
	lcp1_R = 350,
	lcp1_T = 304,
	lcp1_B = 374,
};
enum closeDoor_card_p1
{
	cdcp1_L = 225,
	cdcp1_R = 350,
	cdcp1_T = 394,
	cdcp1_B = 464,
};
enum coef_card_p2
{
	zcp2_L = 951,
	zcp2_R = 1072,
	zcp2_T = 334,
	zcp2_B = 404,
};
enum diceAgain_card_p2
{
	dcp2_L = 951,
	dcp2_R = 1072,
	dcp2_T = 424,
	dcp2_B = 494,
};
enum limit_card_p2
{
	lcp2_L = 951,
	lcp2_R = 1072,
	lcp2_T = 514,
	lcp2_B = 584,
};
enum closeDoor_card_p2
{
	cdcp2_L = 951,
	cdcp2_R = 1072,
	cdcp2_T = 604,
	cdcp2_B = 674,
};
enum charactors
{
	char1,
	char2,
	char3,
	char4,
	char5,
	char6,
	char7,
	char8,
	char9,
};
enum NextGuid_icon
{
	NGI_L = 1114,
	NGI_R = 1215,
	NGI_T = 638,
	NGI_B = 738,
};
enum BackGuid_icon
{
	BGI_L = 990,
	BGI_R = 1091,
	BGI_T = 638,
	BGI_B = 738,
};

enum Guids
{
	guid1,
	guid2,
	guid3,
	guid4,
	guid5,
	guid6,
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
	ALLEGRO_BITMAP* picture_Carridor;
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
	{
		return true;
	}
	else
	{
		//printf("checked swbtn false");
		return false;
	}
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
	must_init(al_init_ttf_addon(), "Font");

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
	must_init(timer, "timer");

	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	must_init(queue, "queue");
	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

	ALLEGRO_DISPLAY* disp = al_create_display(1300, 810);
	must_init(disp, "Window");


	ALLEGRO_FONT* font = al_load_ttf_font("Fonts/Montserrat-Regular.ttf", 30, 1);
	ALLEGRO_FONT* fontText = al_load_ttf_font("Fonts/Montserrat-Regular.ttf", 20, 10);

	ALLEGRO_MOUSE_STATE mouseState;

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(disp));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_mouse_event_source());

	int CardsP1_Assumption[] = { 15,15,15,15 };
	int CardsP2_Assumption[] = { 15,15,15,15 };
#pragma endregion


#pragma region  Variables
	FILE* FileOfBoard;
	fopen_s(&FileOfBoard, "FOB.MiM", "rb");
	if (!FileOfBoard)
	{
		fopen_s(&FileOfBoard, "FOB.MiM", "wb+");
		fclose(FileOfBoard);
	}
	else fclose(FileOfBoard);
	bool sw = true;
	bool done = false;
	bool LinkCursor = false;
	bool Permission_change_mouse = false;
	bool sw_btnDown = false;

	bool IsLimitP1N1 = false;
	bool IsLimitP1N2 = false;
	bool IsLimitP2N1 = false;
	bool IsLimitP2N2 = false;

	bool Tik_Dice = false;
	bool Tik_Nut = false;
	bool Tik_Player = true;

	bool Tik_AGAINDICE = false;
	bool Tik_COEF = false;
	bool Tik_LIMIT = false;

	bool P1N1_IsLive = true;
	bool P1N2_IsLive = true;
	bool P2N1_IsLive = true;
	bool P2N2_IsLive = true;

	bool one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form = false;

	bool one_click_btn_DICEAGAIN_CARD_p1 = true;
	bool one_click_btn_DICEAGAIN_CARD_p2 = true;

	bool one_click_btn_COEF_CARD_p1 = true;
	bool one_click_btn_COEF_CARD_p2 = true;

	bool one_click_btn_LIMIT_CARD_p1 = true;
	bool one_click_btn_LIMIT_CARD_p2 = true;

	bool one_click_btn_NextGuid_icon = true;
	bool one_click_btn_BackGuid_icon = true;

	bool sw_Show_MessageBoxMenu = false;
	bool sw_Show_MessageBoxRefresh = false;

	bool menu_massage_display = false;

	bool Tik_Opinion_ForCarridor = true;

	bool CoefCard_Operated = false;

	bool Frist_Entrance = true;
	bool Is_StartOfBackToMenu = false;
	bool UnLocked_FORDISPLAY_Card_OR_Carridor_Place = false;
	int turn = 1;
	enum Pages pages_sw = FristMenu;

	//variable LOGIC-------------------------
	bool player_Turn = P1;//turn of players

	short int IsDoorClosed = 0;

	short int CoefDice = 1;

	short int sw_AgainDice = 0;

	short int playerSW = 1;

	short int NextPage = 1;

	short int IsBeforeWndow = FristMenu;

	int CardsP1[4] = { CardsP1_Assumption[0],CardsP1_Assumption[1],CardsP1_Assumption[2],CardsP1_Assumption[3] };
	int CardsP2[4] = { CardsP2_Assumption[0],CardsP2_Assumption[1],CardsP2_Assumption[2],CardsP2_Assumption[3] };

	int CardsP1DistanceFromLeft[4] = { 246,246,246,246 };
	int CardsP2DistanceFromLeft[4] = { 1040,1040,1040,1040 };

	int CriterionOfDistanceP1[3] =
	{ P1_SINGLE_DIGIT,
	P1_DOUBLE_DIGIT,
	P1_THREE_DIGIT, };
	int CriterionOfDistanceP2[3] =
	{ P2_SINGLE_DIGIT,
	P2_DOUBLE_DIGIT,
	P2_THREE_DIGIT, };

	int Player1[2] = { 0 }, Player2[2] = { 80,80 };

	int DiceVar = 0;

	int count = 0;

	int iP1 = 0, iP2 = 0;

	int CardChoosed;

	int count_startgame = 0;

	//float X_ProgressBar = 800;

	enum Works_of_player User_operation = -1;

	//-------------------------------------------
	int load_percent = 1;

	struct button btn_Guide;
	btn_Guide.X_frist = PBG_L;
	btn_Guide.Y_frist = PBG_T;
	btn_Guide.X_end = PBG_R;
	btn_Guide.Y_end = PBG_B;
	btn_Guide.sw_Link = Guide_Form;

	struct button btn_NextGuid_icon;
	btn_NextGuid_icon.X_frist = NGI_L;
	btn_NextGuid_icon.Y_frist = NGI_T;
	btn_NextGuid_icon.X_end = NGI_R;
	btn_NextGuid_icon.Y_end = NGI_B;
	btn_NextGuid_icon.sw_Link = Guide_Form;

	struct button btn_BackGuid_icon;
	btn_BackGuid_icon.X_frist = BGI_L;
	btn_BackGuid_icon.Y_frist = BGI_T;
	btn_BackGuid_icon.X_end = BGI_R;
	btn_BackGuid_icon.Y_end = BGI_B;
	btn_BackGuid_icon.sw_Link = Guide_Form;


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

	struct button btn_RefreshInTheBoard;
	btn_RefreshInTheBoard.X_frist = PRBI_L;
	btn_RefreshInTheBoard.Y_frist = PRBI_T;
	btn_RefreshInTheBoard.X_end = PRBI_R;
	btn_RefreshInTheBoard.Y_end = PRBI_B;
	btn_RefreshInTheBoard.sw_Link = NULL;


	struct button btn_QuestionInTheBoard;
	btn_QuestionInTheBoard.X_frist = PQBI_L;
	btn_QuestionInTheBoard.Y_frist = PQBI_T;
	btn_QuestionInTheBoard.X_end = PQBI_R;
	btn_QuestionInTheBoard.Y_end = PQBI_B;
	btn_QuestionInTheBoard.sw_Link = NULL;

	struct button btn_CancelInGuidForm;
	btn_CancelInGuidForm.X_frist = 1300 - 68;
	btn_CancelInGuidForm.Y_frist = 0;
	btn_CancelInGuidForm.X_end = 1300;
	btn_CancelInGuidForm.Y_end = 68;
	btn_CancelInGuidForm.sw_Link = NULL;


	struct button btn_SaveInTheBoard;
	btn_SaveInTheBoard.X_frist = PSI_L;
	btn_SaveInTheBoard.Y_frist = PSI_T;
	btn_SaveInTheBoard.X_end = PSI_R;
	btn_SaveInTheBoard.Y_end = PSI_B;
	btn_SaveInTheBoard.sw_Link = NULL;

	//MenuMassage
	struct button btn_YesInMenuMessageInTheBoard;
	btn_YesInMenuMessageInTheBoard.X_frist = PYIMMIB_L;
	btn_YesInMenuMessageInTheBoard.Y_frist = PYIMMIB_T;
	btn_YesInMenuMessageInTheBoard.X_end = PYIMMIB_R;
	btn_YesInMenuMessageInTheBoard.Y_end = PYIMMIB_B;
	btn_YesInMenuMessageInTheBoard.sw_Link = NULL;

	struct button btn_NoInMenuMessageInTheBoard;
	btn_NoInMenuMessageInTheBoard.X_frist = PNIMMIB_L;
	btn_NoInMenuMessageInTheBoard.Y_frist = PNIMMIB_T;
	btn_NoInMenuMessageInTheBoard.X_end = PNIMMIB_R;
	btn_NoInMenuMessageInTheBoard.Y_end = PNIMMIB_B;
	btn_NoInMenuMessageInTheBoard.sw_Link = NULL;

	struct button btn_CancelInMessages;
	btn_CancelInMessages.X_frist = PCIMI_L;
	btn_CancelInMessages.Y_frist = PCIMI_T;
	btn_CancelInMessages.X_end = PCIMI_R;
	btn_CancelInMessages.Y_end = PCIMI_B;
	btn_CancelInMessages.sw_Link = FristMenu;

	//Notifiction of Carriddor
	struct button btn_CANCEL_NoticeToCarridor;
	btn_CANCEL_NoticeToCarridor.X_frist = PCbNC_L;
	btn_CANCEL_NoticeToCarridor.Y_frist = PCbNC_T;
	btn_CANCEL_NoticeToCarridor.X_end = PCbNC_R;
	btn_CANCEL_NoticeToCarridor.Y_end = PCbNC_B;
	btn_CANCEL_NoticeToCarridor.sw_Link = NULL;

	struct button btn_OK_NoticeToCarridor;
	btn_OK_NoticeToCarridor.X_frist = PObNC_L;
	btn_OK_NoticeToCarridor.Y_frist = PObNC_T;
	btn_OK_NoticeToCarridor.X_end = PObNC_R;
	btn_OK_NoticeToCarridor.Y_end = PObNC_B;
	btn_OK_NoticeToCarridor.sw_Link = NULL;

	//---------------------------
	struct NUT CardPlace[9];
	CardPlace[0].x = 0;
	CardPlace[1].x = 0;
	CardPlace[2].x = 0;
	CardPlace[3].x = 0;
	CardPlace[4].x = 0;
	CardPlace[5].x = 0;
	CardPlace[6].x = 0;
	CardPlace[7].x = 0;
	CardPlace[8].x = 0;
	CardPlace[0].y = 0;
	CardPlace[1].y = 0;
	CardPlace[2].y = 0;
	CardPlace[3].y = 0;
	CardPlace[4].y = 0;
	CardPlace[5].y = 0;
	CardPlace[6].y = 0;
	CardPlace[7].y = 0;
	CardPlace[8].y = 0;

	struct NUT CarridorPlace[8];
	CardPlace[0].x = 0;
	CardPlace[1].x = 0;
	CardPlace[2].x = 0;
	CardPlace[3].x = 0;
	CardPlace[4].x = 0;
	CardPlace[5].x = 0;
	CardPlace[6].x = 0;
	CardPlace[7].x = 0;
	CardPlace[0].y = 0;
	CardPlace[1].y = 0;
	CardPlace[2].y = 0;
	CardPlace[3].y = 0;
	CardPlace[4].y = 0;
	CardPlace[5].y = 0;
	CardPlace[6].y = 0;
	CardPlace[7].y = 0;

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
	ALLEGRO_BITMAP* Dice_PIC_VAR = Dice_PIC[DiceP3];

	ALLEGRO_BITMAP* PIC_2X_forDice = al_load_bitmap("Images/Dice/pic_2x.png");


	ALLEGRO_BITMAP* NutsP1_PIC[3];
	P1Nut1.picture = al_load_bitmap("Images/MOHRE1.png");
	P1Nut1.picture_Carridor = al_load_bitmap("Images/MOHRE1_1.png");
	P1Nut2.picture = al_load_bitmap("Images/MOHRE1.png");

	ALLEGRO_BITMAP* NutsP2_PIC[3];
	P2Nut1.picture = al_load_bitmap("Images/MOHRE2.png");
	P2Nut2.picture = al_load_bitmap("Images/MOHRE2.png");
	P2Nut2.picture_Carridor = al_load_bitmap("Images/MOHRE2_2.png");

	ALLEGRO_BITMAP* lucky_CardP1_PIC[4];
	lucky_CardP1_PIC[Place1] = al_load_bitmap("Images/Cards/closeDoor_cart_p1.png");
	ALLEGRO_BITMAP* NoticeToCarridor = al_load_bitmap("Images/NoticeToEnterTheCarridor.png");
	ALLEGRO_BITMAP* NoticeToCarridor_ProgressBar = al_load_bitmap("Images/ScrollBar.png");
	lucky_CardP1_PIC[Place2] = al_load_bitmap("Images/Cards/zarib_cart_p1.png");
	lucky_CardP1_PIC[Place3] = al_load_bitmap("Images/Cards/limit_cart_p1.png");
	lucky_CardP1_PIC[Place4] = al_load_bitmap("Images/Cards/diceagain_cart_p1.png");
	ALLEGRO_BITMAP* MassageForLimitation = al_load_bitmap("Images/MassageForLimitation.png");

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

	ALLEGRO_BITMAP* Save_Icon = al_load_bitmap("Images/save_icon.png");

	ALLEGRO_BITMAP* MenuFramePic = al_load_bitmap("Images/BLOCK_STOP_menu.png");

	ALLEGRO_BITMAP* CaractersP1_PIC = al_load_bitmap("Images/Caracters/superMan.png");
	ALLEGRO_BITMAP* CaractersP2_PIC = al_load_bitmap("Images/Caracters/strongMan.png");

	ALLEGRO_BITMAP* char_frame_p1 = al_load_bitmap("Images/char_frame_p1.png");
	ALLEGRO_BITMAP* char_frame_p2 = al_load_bitmap("Images/char_frame_p2.png");

	ALLEGRO_BITMAP* charactors_PIC[9];
	charactors_PIC[char1] = al_load_bitmap("Images/Caracters/char_saiyan.png");
	charactors_PIC[char2] = al_load_bitmap("Images/Caracters/char_magnitu.png");
	charactors_PIC[char3] = al_load_bitmap("Images/Caracters/char_gruth.png");
	charactors_PIC[char4] = al_load_bitmap("Images/Caracters/char_magician.png");
	charactors_PIC[char5] = al_load_bitmap("Images/Caracters/char_optimus.png");
	charactors_PIC[char6] = al_load_bitmap("Images/Caracters/char_armord.png");
	charactors_PIC[char7] = al_load_bitmap("Images/Caracters/char_luffy.png");
	charactors_PIC[char8] = al_load_bitmap("Images/Caracters/char_shazam.png");
	charactors_PIC[char9] = al_load_bitmap("Images/Caracters/char_captain.png");

	//Frist
	ALLEGRO_BITMAP* FristMenu_Form_PIC = al_load_bitmap("Images/startMenu/Form.png");
	ALLEGRO_BITMAP* startgame_PIC = al_load_bitmap("Images/startgame.png");
	ALLEGRO_BITMAP* Formcontinue_PIC = al_load_bitmap("Images/Form_continue.png");

	ALLEGRO_BITMAP* MenuInTheBoard_PIC = al_load_bitmap("Images/MessageMenu.png");
	ALLEGRO_BITMAP* RefreshInTheBoard_PIC = al_load_bitmap("Images/MessageRefresh.png");
	ALLEGRO_BITMAP* ContinueAndNewButtonsForm_PIC = al_load_bitmap("Images/first_message.png");


	ALLEGRO_COLOR NutActiveColorP1 = al_map_rgb(200, 191, 231);
	ALLEGRO_COLOR NutActiveColorP2 = al_map_rgb(200, 191, 231);

	//Guide
	ALLEGRO_BITMAP* Guid_page[6];
	Guid_page[guid1] = al_load_bitmap("Images/Guid/1.png");
	Guid_page[guid2] = al_load_bitmap("Images/Guid/2.png");
	Guid_page[guid3] = al_load_bitmap("Images/Guid/3.png");
	Guid_page[guid4] = al_load_bitmap("Images/Guid/4.png");
	Guid_page[guid5] = al_load_bitmap("Images/Guid/5.png");
	Guid_page[guid6] = al_load_bitmap("Images/Guid/6.png");
	ALLEGRO_BITMAP* GuidVar = Guid_page[guid1];

	//Continue&NewbuttonsForm
	ALLEGRO_BITMAP* CarridorPlace_PIC = al_load_bitmap("Images/CarridorPlace.png");
	ALLEGRO_BITMAP* CardLuckPlace_PIC = al_load_bitmap("Images/CardLuckPlace.png");


#pragma endregion
	//fopen_s(&FileOfBoard, "FOB.MiM", "rb+");


	//current Window
	al_start_timer(timer);
	while (1)
	{
		//spitual Vars
		float X_ProgressBar = 800;
		Tik_Opinion_ForCarridor = true;
		//---------------------------------
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
				al_draw_bitmap(Formcontinue_PIC, 0, 0, 0);
				for (int i = 0; i < load_percent && load_percent <= 302; i++)
				{
					al_draw_filled_circle(500.4 + i, 692.6, 10.5, al_map_rgb(255, 255, 255));
				}
				if (load_percent == 302)pages_sw = FristMenu;
				load_percent++;
				break;
			case FristMenu:
#pragma region CodesOf_FristMenu
				if (Permission_change_mouse)
				{
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
					Permission_change_mouse = false;
				}
				al_draw_bitmap(FristMenu_Form_PIC, 0, 0, 0);



				//decrease of ERORE
				if (Is_StartOfBackToMenu)
				{
					al_flip_display();
					Is_StartOfBackToMenu = false;
					al_rest(0.5);
				}
				al_get_mouse_state(&mouseState);
				//click in the buttons
				if (is_Position_btn(mouseState))al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
				else al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

				if (sw_btn(&btn_Guide, &mouseState) && mouseState.buttons == 1)
				{
					pages_sw = Guide_Form;
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
				if (sw_btn(&btn_TWEPERSON_To_buttons_continueANDnew_Form[0], &mouseState))
					if (al_mouse_button_down(&mouseState, 1) && !one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form)
					{
						one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form = true;
						pages_sw = buttons_continueANDnew_Form;
						Permission_change_mouse = true;
						/*if (Frist_Entrance)
						{
							CardPlacesRand(ArrayCardsPlace);
							CarridorPlacesRand(ArrayCarridorsPlace);
							Frist_Entrance = false;
							for (int i = 0; i < 9; i++) printf("%d\n", ArrayCardsPlace[i] + 1);
							for (int i = 0; i < 8; i++)
							{
								for (int j = 0; j < 2; j++)
								{
									printf("%d ", ArrayCarridorsPlace[i][j] + 1);
								}
								printf("\n");
							}
						}*/
						//print in console information of cards and Carridors
					}
					else if (!al_mouse_button_down(&mouseState, 1)) one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form = false;

				if (sw_btn(&btn_TWEPERSON_To_buttons_continueANDnew_Form[1], &mouseState))
					if (al_mouse_button_down(&mouseState, 1) && !one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form)
					{
						IsBeforeWndow = FristMenu;
						one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form = true;
						pages_sw = buttons_continueANDnew_Form;
						Permission_change_mouse = true;
						/*if (Frist_Entrance)
						{
							CardPlacesRand(ArrayCardsPlace);
							CarridorPlacesRand(ArrayCarridorsPlace);
							Frist_Entrance = false;
							for (int i = 0; i < 9; i++) printf("%d\n", ArrayCardsPlace[i] + 1);
							for (int i = 0; i < 8; i++)
							{
								for (int j = 0; j < 2; j++)
								{
									printf("%d ", ArrayCarridorsPlace[i][j] + 1);
								}
								printf("\n");
							}
						}*/
						//print in console information of cards and Carridors


					}
					else if (!al_mouse_button_down(&mouseState, 1)) one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form = false;

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
#pragma region CodesOf_buttons_continueANDnew_Form
				if (Permission_change_mouse)
				{
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
					Permission_change_mouse = false;
				}
				al_draw_bitmap(ContinueAndNewButtonsForm_PIC, 0, 0, 0);
				al_flip_display();
				al_rest(0.5);
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
						al_get_mouse_state(&mouseState);

						//new Game
						if (sw_btn(&btn_NoInMenuMessageInTheBoard, &mouseState))
						{

							if (al_mouse_button_down(&mouseState, 1))
							{
#pragma region RefreshVars_Code
								//Vars///////////////////////////////////////////////////////////////////////
								Permission_change_mouse = false;
								sw_btnDown = false;

								Player1[0] = 0;
								Player1[1] = 0;
								Player2[0] = 80;
								Player2[1] = 80;

								CardsP1[0] = CardsP1_Assumption[0];
								CardsP1[1] = CardsP1_Assumption[1];
								CardsP1[2] = CardsP1_Assumption[2];
								CardsP1[3] = CardsP1_Assumption[3];

								CardsP2[0] = CardsP2_Assumption[0];
								CardsP2[1] = CardsP2_Assumption[1];
								CardsP2[2] = CardsP2_Assumption[2];
								CardsP2[3] = CardsP2_Assumption[3];

								Tik_Dice = false;
								Tik_Nut = false;
								Tik_Player = true;

								Tik_AGAINDICE = false;
								Tik_COEF = false;
								Tik_LIMIT = false;

								P1N1_IsLive = true;
								P1N2_IsLive = true;
								P2N1_IsLive = true;
								P2N2_IsLive = true;

								one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form = false;

								one_click_btn_DICEAGAIN_CARD_p1 = true;
								one_click_btn_DICEAGAIN_CARD_p2 = true;

								one_click_btn_COEF_CARD_p1 = true;
								one_click_btn_COEF_CARD_p2 = true;

								one_click_btn_LIMIT_CARD_p1 = true;
								one_click_btn_LIMIT_CARD_p2 = true;

								one_click_btn_NextGuid_icon = true;
								one_click_btn_BackGuid_icon = true;

								sw_Show_MessageBoxMenu = false;
								sw_Show_MessageBoxRefresh = false;

								menu_massage_display = false;

								Tik_Opinion_ForCarridor = true;

								CoefCard_Operated = false;

								Is_StartOfBackToMenu = false;

								UnLocked_FORDISPLAY_Card_OR_Carridor_Place = false;

								turn = 1;

								//variable LOGIC-------------------------					
								player_Turn = P1;//turn of players							

								IsDoorClosed = 0;

								CoefDice = 1;

								sw_AgainDice = 0;

								NextPage = 1;

								playerSW = 1;

								IsLimitP1N1 = false;
								IsLimitP1N2 = false;
								IsLimitP2N1 = false;
								IsLimitP2N2 = false;

								DiceVar = 0;

								count = 0;

								iP1 = 0;
								iP2 = 0;

								User_operation = -1;
								//---------------------------
								//structs

								btn_P1Nut1.X_frist = PP1N1_L;
								btn_P1Nut1.Y_frist = PP1N1_T;
								btn_P1Nut1.X_end = PP1N1_L + PPNW;
								btn_P1Nut1.Y_end = PP1N1_T + PPNW;
								btn_P1Nut1.sw_Link = NULL;

								btn_P1Nut2.X_frist = PP1N2_L;
								btn_P1Nut2.Y_frist = PP1N2_T;
								btn_P1Nut2.X_end = PP1N2_L + PPNW;
								btn_P1Nut2.Y_end = PP1N2_T + PPNW;
								btn_P1Nut2.sw_Link = NULL;

								btn_P2Nut1.X_frist = PP2N1_L;
								btn_P2Nut1.Y_frist = PP2N1_T;
								btn_P2Nut1.X_end = PP2N1_L + PPNW;
								btn_P2Nut1.Y_end = PP2N1_T + PPNW;
								btn_P2Nut1.sw_Link = NULL;

								btn_P2Nut2.X_frist = PP2N2_L;
								btn_P2Nut2.Y_frist = PP2N2_T;
								btn_P2Nut2.X_end = PP2N2_L + PPNW;
								btn_P2Nut2.Y_end = PP2N2_T + PPNW;
								btn_P2Nut2.sw_Link = NULL;


								//---------------------------
								P1Nut1.x = PP1N1_L;
								P1Nut1.y = PP1N1_T;

								P1Nut2.x = PP1N2_L;
								P1Nut2.y = PP1N2_T;

								P2Nut1.x = PP2N1_L;
								P2Nut1.y = PP2N1_T;

								P2Nut2.x = PP2N2_L;
								P2Nut2.y = PP2N2_T;
								//End////////////////////////////////////////////////////////////////////////
#pragma endregion
								pages_sw = Board_Form;
								//Random Carridors & Cards
								CardPlacesRand(ArrayCardsPlace);
								CarridorPlacesRand(ArrayCarridorsPlace);
								for (int i = 0; i < 9; i++) MoveGraphic(ArrayCardsPlace[i], &(CardPlace[i].x), &(CardPlace[i].y));
								printf("1166\n");
								for (int i = 0; i < 8; i++) MoveGraphic(ArrayCarridorsPlace[i][0], &(CarridorPlace[i].x), &(CarridorPlace[i].y));
								UnLocked_FORDISPLAY_Card_OR_Carridor_Place = true;
								for (int i = 0; i < 9; i++) printf("%d\n", ArrayCardsPlace[i] + 1);
								for (int i = 0; i < 8; i++)
								{
									for (int j = 0; j < 2; j++)
									{
										printf("%d ", ArrayCarridorsPlace[i][j] + 1);
									}
									printf("\n");

								}

								break;
							}

						}
						//Seved Game
						else if (sw_btn(&btn_YesInMenuMessageInTheBoard, &mouseState))
						{
							if (al_mouse_button_down(&mouseState, 1))
							{
								char chj = '0';
								fopen_s(&FileOfBoard, "FOB.MiM", "rb");
								if (!FileOfBoard)
								{
									printf("ERORE IN LOAD FILE\n");
									fclose(FileOfBoard);
									exit(504);
								}
								fread(&chj, sizeof(char), 1, FileOfBoard);

								if (feof(FileOfBoard))	printf("Not Fount Saved Game");
								else
								{
									fseek(FileOfBoard, 0, SEEK_SET);

									fread(&Permission_change_mouse, sizeof(bool), 1, FileOfBoard);
									fread(&sw_btnDown, sizeof(bool), 1, FileOfBoard);

									fread(Player1, sizeof(int), 2, FileOfBoard);
									fread(Player2, sizeof(int), 2, FileOfBoard);

									fread(CardsP1, sizeof(int), 4, FileOfBoard);

									fread(CardsP2, sizeof(int), 4, FileOfBoard);

									fread(&Tik_Dice, sizeof(bool), 1, FileOfBoard);
									fread(&Tik_Nut, sizeof(bool), 1, FileOfBoard);
									fread(&Tik_Player, sizeof(bool), 1, FileOfBoard);

									fread(&Tik_AGAINDICE, sizeof(bool), 1, FileOfBoard);
									fread(&Tik_COEF, sizeof(bool), 1, FileOfBoard);
									fread(&Tik_LIMIT, sizeof(bool), 1, FileOfBoard);

									fread(&P1N1_IsLive, sizeof(bool), 1, FileOfBoard);
									fread(&P1N2_IsLive, sizeof(bool), 1, FileOfBoard);
									fread(&P2N1_IsLive, sizeof(bool), 1, FileOfBoard);
									fread(&P2N2_IsLive, sizeof(bool), 1, FileOfBoard);

									fread(&one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form, sizeof(bool), 1, FileOfBoard);

									fread(&one_click_btn_DICEAGAIN_CARD_p1, sizeof(bool), 1, FileOfBoard);
									fread(&one_click_btn_DICEAGAIN_CARD_p2, sizeof(bool), 1, FileOfBoard);

									fread(&one_click_btn_COEF_CARD_p1, sizeof(bool), 1, FileOfBoard);
									fread(&one_click_btn_COEF_CARD_p2, sizeof(bool), 1, FileOfBoard);

									fread(&one_click_btn_LIMIT_CARD_p1, sizeof(bool), 1, FileOfBoard);
									fread(&one_click_btn_LIMIT_CARD_p2, sizeof(bool), 1, FileOfBoard);

									fread(&one_click_btn_NextGuid_icon, sizeof(bool), 1, FileOfBoard);
									fread(&one_click_btn_BackGuid_icon, sizeof(bool), 1, FileOfBoard);

									fread(&sw_Show_MessageBoxMenu, sizeof(bool), 1, FileOfBoard);
									fread(&sw_Show_MessageBoxRefresh, sizeof(bool), 1, FileOfBoard);

									fread(&menu_massage_display, sizeof(bool), 1, FileOfBoard);

									fread(&Tik_Opinion_ForCarridor, sizeof(bool), 1, FileOfBoard);

									fread(&CoefCard_Operated, sizeof(bool), 1, FileOfBoard);

									fread(&Is_StartOfBackToMenu, sizeof(bool), 1, FileOfBoard);

									fread(&UnLocked_FORDISPLAY_Card_OR_Carridor_Place, sizeof(bool), 1, FileOfBoard);

									fread(&turn, sizeof(int), 1, FileOfBoard);

									//Variable LOGIC------------------------------
									fread(&player_Turn, sizeof(bool), 1, FileOfBoard);

									fread(&IsDoorClosed, sizeof(IsDoorClosed), 1, FileOfBoard);

									fread(&CoefDice, sizeof(CoefDice), 1, FileOfBoard);

									fread(&sw_AgainDice, sizeof(sw_AgainDice), 1, FileOfBoard);

									fread(&NextPage, sizeof(NextPage), 1, FileOfBoard);

									fread(&playerSW, sizeof(playerSW), 1, FileOfBoard);

									fread(&IsLimitP1N1, sizeof(bool), 1, FileOfBoard);
									fread(&IsLimitP1N2, sizeof(bool), 1, FileOfBoard);
									fread(&IsLimitP2N1, sizeof(bool), 1, FileOfBoard);
									fread(&IsLimitP2N2, sizeof(bool), 1, FileOfBoard);

									fread(&DiceVar, sizeof(int), 1, FileOfBoard);

									fread(&count, sizeof(int), 1, FileOfBoard);

									fread(&iP1, sizeof(int), 1, FileOfBoard);
									fread(&iP2, sizeof(int), 1, FileOfBoard);

									fread(&User_operation, sizeof(User_operation), 1, FileOfBoard);
									//----------------------------------------------------------------
									//structs---------------------------

									fread(&btn_P1Nut1, sizeof(struct button), 1, FileOfBoard);
									fread(&btn_P1Nut2, sizeof(struct button), 1, FileOfBoard);
									fread(&btn_P2Nut1, sizeof(struct button), 1, FileOfBoard);
									fread(&btn_P2Nut2, sizeof(struct button), 1, FileOfBoard);

									fread(&P1Nut1.x, sizeof(int), 1, FileOfBoard);
									fread(&P1Nut1.y, sizeof(int), 1, FileOfBoard);

									fread(&P1Nut2.x, sizeof(int), 1, FileOfBoard);
									fread(&P1Nut2.y, sizeof(int), 1, FileOfBoard);

									fread(&P2Nut1.x, sizeof(int), 1, FileOfBoard);
									fread(&P2Nut1.y, sizeof(int), 1, FileOfBoard);

									fread(&P2Nut2.x, sizeof(int), 1, FileOfBoard);
									fread(&P2Nut2.y, sizeof(int), 1, FileOfBoard);

									fread(CardPlace, sizeof(struct NUT), 9, FileOfBoard);
									fread(CarridorPlace, sizeof(struct NUT), 8, FileOfBoard);

									fread(ArrayCardsPlace, sizeof(int), 9, FileOfBoard);

									for (int i = 0; i < 8; i++)fread(&(ArrayCarridorsPlace[i][0]), sizeof(int), 1, FileOfBoard);

									for (int i = 0; i < 8; i++) fread(&(ArrayCarridorsPlace[i][1]), sizeof(int), 1, FileOfBoard);

									//----------------------------------------
									fseek(FileOfBoard, 0, SEEK_SET);
									fclose(FileOfBoard);

									ConvertToDiceArray(&DiceVar);
									Dice_PIC_VAR = Dice_PIC[DiceVar];
									ConvertToDiceMIM(&DiceVar);

									pages_sw = Board_Form;
									break;
								}
								fclose(FileOfBoard);
							}
						}
						else if (sw_btn(&btn_CancelInMessages, &mouseState))
						{
							if (al_mouse_button_down(&mouseState, 1))
							{
								pages_sw = FristMenu;
								//Load Seved Game-----------------------

								break;
							}

						}
					}
				}
#pragma endregion
				break;
			case Template_Form:
				break;
			case Guide_Form:
				if (Permission_change_mouse)
				{
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
					Permission_change_mouse = false;
				}
				al_draw_bitmap(GuidVar, 0, 0, 0);
				al_get_mouse_state(&mouseState);
				if (sw_btn(&btn_NextGuid_icon, &mouseState))
				{
					if (mouseState.buttons == 1 && !one_click_btn_NextGuid_icon)
					{
						one_click_btn_NextGuid_icon = true;

						if (NextPage != 6) NextPage++;

						switch (NextPage)
						{
						case 2: GuidVar = Guid_page[guid2];
							break;
						case 3:GuidVar = Guid_page[guid3];
							break;
						case 4: GuidVar = Guid_page[guid4];
							break;
						case 5: GuidVar = Guid_page[guid5];
							break;
						case 6:GuidVar = Guid_page[guid6];
							break;
						default:GuidVar = Guid_page[guid1];
							break;
						}

					}
					else if (!al_mouse_button_down(&mouseState, 1)) one_click_btn_NextGuid_icon = false;
				}
				if (sw_btn(&btn_BackGuid_icon, &mouseState))
				{
					if (mouseState.buttons == 1 && !one_click_btn_BackGuid_icon)
					{
						one_click_btn_BackGuid_icon = true;

						if (NextPage != 1) NextPage--;

						switch (NextPage)
						{
						case 2: GuidVar = Guid_page[guid2];
							break;
						case 3:GuidVar = Guid_page[guid3];
							break;
						case 4: GuidVar = Guid_page[guid4];
							break;
						case 5: GuidVar = Guid_page[guid5];
							break;
						case 6:GuidVar = Guid_page[guid6];
							break;
						default:GuidVar = Guid_page[guid1];
							break;
						}

					}
					else if (!al_mouse_button_down(&mouseState, 1)) one_click_btn_BackGuid_icon = false;
				}
				if (sw_btn(&btn_CancelInGuidForm, &mouseState))
				{
					if (al_mouse_button_down(&mouseState, 1))
					{
						if (IsBeforeWndow == FristMenu) pages_sw = FristMenu;
						else if (IsBeforeWndow == Board_Form) pages_sw = Board_Form;
						NextPage = 1;
						GuidVar = Guid_page[guid1];
					}
				}
				break;
			case AboutUs_Form:
				break;
			case Setting_Form:
				break;
			case Board_Form:
#pragma region codesOf_BoardForm
				if (Permission_change_mouse)
				{
					al_set_system_mouse_cursor(disp, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
					Permission_change_mouse = false;
				}

				al_draw_text(font, al_map_rgb(5, 100, 12), 0, 0, 0, "0");
				al_get_mouse_state(&mouseState);
				al_clear_to_color(al_map_rgb(240, 240, 240));
				//Board & cards------------------------------
				al_get_mouse_state(&mouseState);

				al_draw_bitmap(lucky_CardP1_PIC[Place1], cdcp1_L, cdcp1_T, 0);
				al_draw_bitmap(lucky_CardP1_PIC[Place2], zcp1_L, zcp1_T, 0);

				if (Tik_Dice)
					if (!Tik_COEF)
						if (player_Turn == P1)
							if (sw_btn(&btn_coef_card_p1, &mouseState))
							{
								if (al_mouse_button_down(&mouseState, 1) && !one_click_btn_COEF_CARD_p1)
								{
									if (CardsP1[COEF])
									{
										one_click_btn_COEF_CARD_p1 = true;
										CardsP1[COEF]--;
										Tik_COEF = true;
										User_operation = CLICKDICE;
									}
								}
								else if (!al_mouse_button_down(&mouseState, 1)) one_click_btn_COEF_CARD_p1 = false;
							}
				al_get_mouse_state(&mouseState);
				al_draw_bitmap(lucky_CardP1_PIC[Place3], lcp1_L, lcp1_T, 0);
				if (Tik_Dice)
					if (!Tik_LIMIT)
						if (player_Turn == P1)
							if (sw_btn(&btn_limit_card_p1, &mouseState))
							{
								if (al_mouse_button_down(&mouseState, 1) && !one_click_btn_LIMIT_CARD_p1)
								{
									if (CardsP1[LIMIT])
									{
										one_click_btn_LIMIT_CARD_p1 = true;
										CardsP1[LIMIT]--;
										Tik_LIMIT = true;
										User_operation = CLICKCARD_limit;
									}
								}
								else if (!al_mouse_button_down(&mouseState, 1)) one_click_btn_LIMIT_CARD_p1 = false;

							}
				al_draw_bitmap(lucky_CardP1_PIC[Place4], dcp1_L, dcp1_T, 0);
				if (Tik_Dice)
					if (!Tik_AGAINDICE)
						if (player_Turn == P1)
							if (sw_btn(&btn_diceAgain_card_p1, &mouseState))
							{
								if (al_mouse_button_down(&mouseState, 1) && !one_click_btn_DICEAGAIN_CARD_p1)
								{
									one_click_btn_DICEAGAIN_CARD_p1 = true;
									if (CardsP1[DICEAGAIN])
									{
										CardsP1[DICEAGAIN]--;
										Tik_AGAINDICE = true;
										User_operation = CLICKDICE;
									}
								}
								else if (!al_mouse_button_down(&mouseState, 1)) one_click_btn_DICEAGAIN_CARD_p1 = false;
							}
				al_draw_bitmap(lucky_CardP2_PIC[Place1], cdcp2_L, cdcp2_T, 0);
				al_draw_bitmap(lucky_CardP2_PIC[Place2], zcp2_L, zcp2_T, 0);
				if (Tik_Dice)
					if (!Tik_COEF)
						if (player_Turn == P2)
							if (sw_btn(&btn_coef_card_p2, &mouseState))
							{
								if (al_mouse_button_down(&mouseState, 1) && !one_click_btn_COEF_CARD_p2)
								{
									if (CardsP2[COEF])
									{
										one_click_btn_COEF_CARD_p2 = true;
										CardsP2[COEF]--;
										Tik_COEF = true;
										User_operation = CLICKDICE;
									}
								}
								else if (!al_mouse_button_down(&mouseState, 1)) one_click_btn_COEF_CARD_p2 = false;
							}
				al_draw_bitmap(lucky_CardP2_PIC[Place3], lcp2_L, lcp2_T, 0);
				if (Tik_Dice)
					if (!Tik_LIMIT)
						if (player_Turn == P2)
							if (sw_btn(&btn_limit_card_p2, &mouseState))
							{
								if (al_mouse_button_down(&mouseState, 1) && !one_click_btn_LIMIT_CARD_p2)
								{
									if (CardsP2[LIMIT])
									{
										one_click_btn_LIMIT_CARD_p2 = true;
										CardsP2[LIMIT]--;
										Tik_LIMIT = true;
										User_operation = CLICKCARD_limit;
									}
								}
								else if (!al_mouse_button_down(&mouseState, 1)) one_click_btn_LIMIT_CARD_p2 = false;

							}
				al_draw_bitmap(lucky_CardP2_PIC[Place4], dcp2_L, dcp2_T, 0);
				if (Tik_Dice)
					if (!Tik_AGAINDICE)
						if (player_Turn == P2)
							if (sw_btn(&btn_diceAgain_card_p2, &mouseState))
							{
								if (al_mouse_button_down(&mouseState, 1) && !one_click_btn_DICEAGAIN_CARD_p2)
								{
									one_click_btn_DICEAGAIN_CARD_p2 = true;
									if (CardsP2[DICEAGAIN])
									{
										CardsP2[DICEAGAIN]--;
										Tik_AGAINDICE = true;
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

				//Carridors & Card Place PIC
				for (int i = 0; i < 9; i++)
					al_draw_bitmap(CardLuckPlace_PIC, CardPlace[i].x, CardPlace[i].y, 0);
				for (int i = 0; i < 8; i++)
					al_draw_bitmap(CarridorPlace_PIC, CarridorPlace[i].x, CarridorPlace[i].y, 0);

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
				if (!IsLimitP1N1)if (player_Turn == P1)
				{
					if (Tik_Dice) NutActiveColorP1 = al_map_rgb(247, 173, 175);
					else NutActiveColorP1 = al_map_rgb(200, 191, 231);
					al_draw_circle(P1Nut1.x + PPNW / 2 - 1, P1Nut1.y + PPNW / 2, PPNW / 2, NutActiveColorP1, 5);
				}
				al_draw_bitmap(P1Nut1.picture, P1Nut1.x, P1Nut1.y, 0);

				if (!IsLimitP1N2)if (player_Turn == P1)
				{
					if (Tik_Dice) NutActiveColorP1 = al_map_rgb(247, 173, 175);
					else NutActiveColorP1 = al_map_rgb(200, 191, 231);
					al_draw_circle(P1Nut2.x + PPNW / 2 - 1, P1Nut2.y + PPNW / 2, PPNW / 2, NutActiveColorP1, 5);
				}
				al_draw_bitmap(P1Nut2.picture, P1Nut2.x, P1Nut2.y, 0);

				if (!IsLimitP2N1)if (player_Turn == P2)
				{
					if (Tik_Dice) NutActiveColorP2 = al_map_rgb(145, 216, 247);
					else NutActiveColorP2 = al_map_rgb(200, 191, 231);
					al_draw_circle(P2Nut1.x + PPNW / 2 - 1, P2Nut1.y + PPNW / 2, PPNW / 2, NutActiveColorP2, 5);
				}
				al_draw_bitmap(P2Nut1.picture, P2Nut1.x, P2Nut1.y, 0);

				if (!IsLimitP2N2)if (player_Turn == P2)
				{
					if (Tik_Dice) NutActiveColorP2 = al_map_rgb(145, 216, 247);
					else NutActiveColorP2 = al_map_rgb(200, 191, 231);
					al_draw_circle(P2Nut2.x + PPNW / 2 - 1, P2Nut2.y + PPNW / 2, PPNW / 2, NutActiveColorP2, 5);
				}
				al_draw_bitmap(P2Nut2.picture, P2Nut2.x, P2Nut2.y, 0);

				if (Tik_Dice)
				{
					//click nuts

					al_get_mouse_state(&mouseState);
					if (sw_btn(&btn_P1Nut1, &mouseState))
					{
						if (!IsLimitP1N1)
							if (P1N1_IsLive)
								if (al_mouse_button_down(&mouseState, 1))
								{
									IsLimitP1N2 = false;
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
						if (!IsLimitP1N2)
							if (P1N2_IsLive)
								if (al_mouse_button_down(&mouseState, 1))
								{
									IsLimitP1N1 = false;
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
						if (!IsLimitP2N1)
							if (P2N1_IsLive)
								if (al_mouse_button_down(&mouseState, 1))
								{
									IsLimitP2N2 = false;
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
						if (!IsLimitP2N2)
							if (P2N2_IsLive)
								if (al_mouse_button_down(&mouseState, 1))
								{
									IsLimitP2N1 = false;
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
				al_draw_bitmap(char_frame_p1, 95, 536, 0);
				al_draw_bitmap(char_frame_p2, 1000, 76, 0);
				al_draw_bitmap(charactors_PIC[char3], 115, 568, 0);
				al_draw_bitmap(charactors_PIC[char1], 1020, 108, 0);

				//-----------------------------------------

				//Menu Frame-------------------------------
				al_draw_bitmap(MenuFramePic, 25, -12, 0);
				al_draw_bitmap(Menu_InTheBoard_Icon, 35, -5, 0);
				al_draw_bitmap(RefreshIcon, 105, -5, 0);
				al_draw_bitmap(GuideIcon, 170, -5, 0);
				al_draw_bitmap(Save_Icon, 240, -5, 0);

				al_get_mouse_state(&mouseState);

				//idea of menu Message
				//******************************************************
				if (sw_btn(&btn_MenuInTheBoard, &mouseState))
				{
					if (al_mouse_button_down(&mouseState, 1))
					{
						sw_Show_MessageBoxMenu = true;
					}
				}
				//Menu Button
				if (sw_Show_MessageBoxMenu)
				{

					al_draw_bitmap(MenuInTheBoard_PIC, 0, 0, 0);
					al_flip_display();
					while (1)
					{
						al_wait_for_event(queue, &event);
						al_get_mouse_state(&mouseState);
						//NO
						if (sw_btn(&btn_YesInMenuMessageInTheBoard, &mouseState))
						{
							if (al_mouse_button_down(&mouseState, 1))
							{
								sw_Show_MessageBoxMenu = false;
								break;
							}
						}
						//YES
						else if (sw_btn(&btn_NoInMenuMessageInTheBoard, &mouseState))
						{
							if (al_mouse_button_down(&mouseState, 1))
							{
								fopen_s(&FileOfBoard, "FOB.MiM", "wb");
								//SAVE Information---------------------------------------------------------
								//fseek(FileOfBoard, 0, SEEK_SET);

								fwrite(&Permission_change_mouse, sizeof(bool), 1, FileOfBoard);
								fwrite(&sw_btnDown, sizeof(bool), 1, FileOfBoard);

								printf("%d", sw_btnDown);


								fwrite(Player1, sizeof(int), 2, FileOfBoard);
								fwrite(Player2, sizeof(int), 2, FileOfBoard);

								fwrite(CardsP1, sizeof(int), 4, FileOfBoard);
								fwrite(CardsP2, sizeof(int), 4, FileOfBoard);

								fwrite(&Tik_Dice, sizeof(bool), 1, FileOfBoard);
								fwrite(&Tik_Nut, sizeof(bool), 1, FileOfBoard);
								fwrite(&Tik_Player, sizeof(bool), 1, FileOfBoard);

								fwrite(&Tik_AGAINDICE, sizeof(bool), 1, FileOfBoard);
								fwrite(&Tik_COEF, sizeof(bool), 1, FileOfBoard);
								fwrite(&Tik_LIMIT, sizeof(bool), 1, FileOfBoard);

								fwrite(&P1N1_IsLive, sizeof(bool), 1, FileOfBoard);
								fwrite(&P1N2_IsLive, sizeof(bool), 1, FileOfBoard);
								fwrite(&P2N1_IsLive, sizeof(bool), 1, FileOfBoard);
								fwrite(&P2N2_IsLive, sizeof(bool), 1, FileOfBoard);

								fwrite(&one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form, sizeof(bool), 1, FileOfBoard);

								fwrite(&one_click_btn_DICEAGAIN_CARD_p1, sizeof(bool), 1, FileOfBoard);
								fwrite(&one_click_btn_DICEAGAIN_CARD_p2, sizeof(bool), 1, FileOfBoard);

								fwrite(&one_click_btn_COEF_CARD_p1, sizeof(bool), 1, FileOfBoard);
								fwrite(&one_click_btn_COEF_CARD_p2, sizeof(bool), 1, FileOfBoard);

								fwrite(&one_click_btn_LIMIT_CARD_p1, sizeof(bool), 1, FileOfBoard);
								fwrite(&one_click_btn_LIMIT_CARD_p2, sizeof(bool), 1, FileOfBoard);

								fwrite(&one_click_btn_NextGuid_icon, sizeof(bool), 1, FileOfBoard);
								fwrite(&one_click_btn_BackGuid_icon, sizeof(bool), 1, FileOfBoard);

								fwrite(&sw_Show_MessageBoxMenu, sizeof(bool), 1, FileOfBoard);
								fwrite(&sw_Show_MessageBoxRefresh, sizeof(bool), 1, FileOfBoard);

								fwrite(&menu_massage_display, sizeof(bool), 1, FileOfBoard);

								fwrite(&Tik_Opinion_ForCarridor, sizeof(bool), 1, FileOfBoard);

								fwrite(&CoefCard_Operated, sizeof(bool), 1, FileOfBoard);

								fwrite(&Is_StartOfBackToMenu, sizeof(bool), 1, FileOfBoard);

								fwrite(&UnLocked_FORDISPLAY_Card_OR_Carridor_Place, sizeof(bool), 1, FileOfBoard);

								fwrite(&turn, sizeof(int), 1, FileOfBoard);

								//VarsLOGIC------------------------------
								fwrite(&player_Turn, sizeof(bool), 1, FileOfBoard);

								fwrite(&IsDoorClosed, sizeof(IsDoorClosed), 1, FileOfBoard);

								fwrite(&CoefDice, sizeof(CoefDice), 1, FileOfBoard);

								fwrite(&sw_AgainDice, sizeof(sw_AgainDice), 1, FileOfBoard);

								fwrite(&NextPage, sizeof(NextPage), 1, FileOfBoard);

								fwrite(&playerSW, sizeof(playerSW), 1, FileOfBoard);

								fwrite(&IsLimitP1N1, sizeof(bool), 1, FileOfBoard);
								fwrite(&IsLimitP1N2, sizeof(bool), 1, FileOfBoard);
								fwrite(&IsLimitP2N1, sizeof(bool), 1, FileOfBoard);
								fwrite(&IsLimitP2N2, sizeof(bool), 1, FileOfBoard);

								fwrite(&DiceVar, sizeof(int), 1, FileOfBoard);

								fwrite(&count, sizeof(int), 1, FileOfBoard);

								fwrite(&iP1, sizeof(int), 1, FileOfBoard);
								fwrite(&iP2, sizeof(int), 1, FileOfBoard);

								fwrite(&User_operation, sizeof(User_operation), 1, FileOfBoard);
								//----------------------------------------------------------------------
								//structs---------------------------

								fwrite(&btn_P1Nut1, sizeof(struct button), 1, FileOfBoard);
								fwrite(&btn_P1Nut2, sizeof(struct button), 1, FileOfBoard);
								fwrite(&btn_P2Nut1, sizeof(struct button), 1, FileOfBoard);
								fwrite(&btn_P2Nut2, sizeof(struct button), 1, FileOfBoard);

								fwrite(&P1Nut1.x, sizeof(int), 1, FileOfBoard);
								fwrite(&P1Nut1.y, sizeof(int), 1, FileOfBoard);

								fwrite(&P1Nut2.x, sizeof(int), 1, FileOfBoard);
								fwrite(&P1Nut2.y, sizeof(int), 1, FileOfBoard);

								fwrite(&P2Nut1.x, sizeof(int), 1, FileOfBoard);
								fwrite(&P2Nut1.y, sizeof(int), 1, FileOfBoard);

								fwrite(&P2Nut2.x, sizeof(int), 1, FileOfBoard);
								fwrite(&P2Nut2.y, sizeof(int), 1, FileOfBoard);

								fwrite(CardPlace, sizeof(struct NUT), 9, FileOfBoard);
								fwrite(CarridorPlace, sizeof(struct NUT), 8, FileOfBoard);

								fread(ArrayCardsPlace, sizeof(int), 9, FileOfBoard);

								for (int i = 0; i < 8; i++)fwrite(&(ArrayCarridorsPlace[i][0]), sizeof(int), 1, FileOfBoard);

								for (int i = 0; i < 8; i++) fwrite(&(ArrayCarridorsPlace[i][1]), sizeof(int), 1, FileOfBoard);

								//----------------------------------------
								fseek(FileOfBoard, 0, SEEK_SET);
								fclose(FileOfBoard);
								//-------------------------------------------------------------------------
								sw_Show_MessageBoxMenu = false;
								Is_StartOfBackToMenu = true;
								pages_sw = FristMenu;
								break;
							}
						}

					}
				}
				//Refresh Button
				if (sw_btn(&btn_RefreshInTheBoard, &mouseState))
				{
					if (al_mouse_button_down(&mouseState, 1))
					{
						sw_Show_MessageBoxRefresh = true;
					}
				}
				if (sw_Show_MessageBoxRefresh)
				{
					//Refresh Button
					al_draw_bitmap(RefreshInTheBoard_PIC, 0, 0, 0);
					al_flip_display();
					while (1)
					{
						al_wait_for_event(queue, &event);
						al_get_mouse_state(&mouseState);
						if (sw_btn(&btn_NoInMenuMessageInTheBoard, &mouseState))
						{

							if (al_mouse_button_down(&mouseState, 1))
							{
								sw_Show_MessageBoxRefresh = false;

								//Vars///////////////////////////////////////////////////////////////////////
								Player1[0] = 0;
								Player1[1] = 0;
								Player2[0] = 80;
								Player2[1] = 80;

								CardsP1[0] = CardsP1_Assumption[0];
								CardsP1[1] = CardsP1_Assumption[1];
								CardsP1[2] = CardsP1_Assumption[2];
								CardsP1[3] = CardsP1_Assumption[3];

								CardsP2[0] = CardsP2_Assumption[0];
								CardsP2[1] = CardsP2_Assumption[1];
								CardsP2[2] = CardsP2_Assumption[2];
								CardsP2[3] = CardsP2_Assumption[3];

								Tik_Dice = false;
								Tik_Nut = false;
								Tik_Player = true;

								Tik_AGAINDICE = false;
								Tik_COEF = false;
								Tik_LIMIT = false;

								P1N1_IsLive = true;
								P1N2_IsLive = true;
								P2N1_IsLive = true;
								P2N2_IsLive = true;

								one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form = false;

								one_click_btn_DICEAGAIN_CARD_p1 = true;
								one_click_btn_DICEAGAIN_CARD_p2 = true;

								one_click_btn_COEF_CARD_p1 = true;
								one_click_btn_COEF_CARD_p2 = true;

								one_click_btn_LIMIT_CARD_p1 = true;
								one_click_btn_LIMIT_CARD_p2 = true;

								turn = 1;

								//variable LOGIC-------------------------					
								player_Turn = P1;//turn of players							

								IsDoorClosed = 0;

								CoefDice = 1;

								sw_AgainDice = 0;

								playerSW = 1;

								IsLimitP1N1 = false;
								IsLimitP1N2 = false;
								IsLimitP2N1 = false;
								IsLimitP2N2 = false;

								DiceVar = 0;

								count = 0;

								iP1 = 0;
								iP2 = 0;

								CardChoosed;

								User_operation = -1;
								//---------------------------
								//structs

								btn_P1Nut1.X_frist = PP1N1_L;
								btn_P1Nut1.Y_frist = PP1N1_T;
								btn_P1Nut1.X_end = PP1N1_L + PPNW;
								btn_P1Nut1.Y_end = PP1N1_T + PPNW;
								btn_P1Nut1.sw_Link = NULL;

								btn_P1Nut2.X_frist = PP1N2_L;
								btn_P1Nut2.Y_frist = PP1N2_T;
								btn_P1Nut2.X_end = PP1N2_L + PPNW;
								btn_P1Nut2.Y_end = PP1N2_T + PPNW;
								btn_P1Nut2.sw_Link = NULL;

								btn_P2Nut1.X_frist = PP2N1_L;
								btn_P2Nut1.Y_frist = PP2N1_T;
								btn_P2Nut1.X_end = PP2N1_L + PPNW;
								btn_P2Nut1.Y_end = PP2N1_T + PPNW;
								btn_P2Nut1.sw_Link = NULL;

								btn_P2Nut2.X_frist = PP2N2_L;
								btn_P2Nut2.Y_frist = PP2N2_T;
								btn_P2Nut2.X_end = PP2N2_L + PPNW;
								btn_P2Nut2.Y_end = PP2N2_T + PPNW;
								btn_P2Nut2.sw_Link = NULL;


								//---------------------------
								P1Nut1.x = PP1N1_L;
								P1Nut1.y = PP1N1_T;

								P1Nut2.x = PP1N2_L;
								P1Nut2.y = PP1N2_T;

								P2Nut1.x = PP2N1_L;
								P2Nut1.y = PP2N1_T;

								P2Nut2.x = PP2N2_L;
								P2Nut2.y = PP2N2_T;
								//End////////////////////////////////////////////////////////////////////////
								break;
							}
						}
						else if (sw_btn(&btn_YesInMenuMessageInTheBoard, &mouseState))
						{
							if (al_mouse_button_down(&mouseState, 1))
							{
								sw_Show_MessageBoxRefresh = false;
								break;
							}
						}

					}
				}
				//Guid Button
				if (sw_btn(&btn_QuestionInTheBoard, &mouseState))
				{
					if (al_mouse_button_down(&mouseState, 1))
					{
						pages_sw = Guide_Form;
						IsBeforeWndow = Board_Form;
					}
				}

				//Save Button
				if (sw_btn(&btn_SaveInTheBoard, &mouseState))
					if (al_mouse_button_down(&mouseState, 1))
					{
						fopen_s(&FileOfBoard, "FOB.MiM", "wb");
						//SAVE Information---------------------------------------------------------
						//fseek(FileOfBoard, 0, SEEK_SET);

						fwrite(&Permission_change_mouse, sizeof(bool), 1, FileOfBoard);
						fwrite(&sw_btnDown, sizeof(bool), 1, FileOfBoard);

						fwrite(Player1, sizeof(int), 2, FileOfBoard);
						fwrite(Player2, sizeof(int), 2, FileOfBoard);

						fwrite(CardsP1, sizeof(int), 4, FileOfBoard);
						fwrite(CardsP2, sizeof(int), 4, FileOfBoard);

						fwrite(&Tik_Dice, sizeof(bool), 1, FileOfBoard);
						fwrite(&Tik_Nut, sizeof(bool), 1, FileOfBoard);
						fwrite(&Tik_Player, sizeof(bool), 1, FileOfBoard);

						fwrite(&Tik_AGAINDICE, sizeof(bool), 1, FileOfBoard);
						fwrite(&Tik_COEF, sizeof(bool), 1, FileOfBoard);
						fwrite(&Tik_LIMIT, sizeof(bool), 1, FileOfBoard);

						fwrite(&P1N1_IsLive, sizeof(bool), 1, FileOfBoard);
						fwrite(&P1N2_IsLive, sizeof(bool), 1, FileOfBoard);
						fwrite(&P2N1_IsLive, sizeof(bool), 1, FileOfBoard);
						fwrite(&P2N2_IsLive, sizeof(bool), 1, FileOfBoard);

						fwrite(&one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form, sizeof(bool), 1, FileOfBoard);

						fwrite(&one_click_btn_DICEAGAIN_CARD_p1, sizeof(bool), 1, FileOfBoard);
						fwrite(&one_click_btn_DICEAGAIN_CARD_p2, sizeof(bool), 1, FileOfBoard);

						fwrite(&one_click_btn_COEF_CARD_p1, sizeof(bool), 1, FileOfBoard);
						fwrite(&one_click_btn_COEF_CARD_p2, sizeof(bool), 1, FileOfBoard);

						fwrite(&one_click_btn_LIMIT_CARD_p1, sizeof(bool), 1, FileOfBoard);
						fwrite(&one_click_btn_LIMIT_CARD_p2, sizeof(bool), 1, FileOfBoard);

						fwrite(&one_click_btn_NextGuid_icon, sizeof(bool), 1, FileOfBoard);
						fwrite(&one_click_btn_BackGuid_icon, sizeof(bool), 1, FileOfBoard);

						fwrite(&sw_Show_MessageBoxMenu, sizeof(bool), 1, FileOfBoard);
						fwrite(&sw_Show_MessageBoxRefresh, sizeof(bool), 1, FileOfBoard);

						fwrite(&menu_massage_display, sizeof(bool), 1, FileOfBoard);

						fwrite(&Tik_Opinion_ForCarridor, sizeof(bool), 1, FileOfBoard);

						fwrite(&CoefCard_Operated, sizeof(bool), 1, FileOfBoard);

						fwrite(&Is_StartOfBackToMenu, sizeof(bool), 1, FileOfBoard);

						fwrite(&UnLocked_FORDISPLAY_Card_OR_Carridor_Place, sizeof(bool), 1, FileOfBoard);

						fwrite(&turn, sizeof(int), 1, FileOfBoard);

						//VarsLOGIC------------------------------
						fwrite(&player_Turn, sizeof(bool), 1, FileOfBoard);

						fwrite(&IsDoorClosed, sizeof(IsDoorClosed), 1, FileOfBoard);

						fwrite(&CoefDice, sizeof(CoefDice), 1, FileOfBoard);

						fwrite(&sw_AgainDice, sizeof(sw_AgainDice), 1, FileOfBoard);

						fwrite(&NextPage, sizeof(NextPage), 1, FileOfBoard);

						fwrite(&playerSW, sizeof(playerSW), 1, FileOfBoard);

						fwrite(&IsLimitP1N1, sizeof(bool), 1, FileOfBoard);
						fwrite(&IsLimitP1N2, sizeof(bool), 1, FileOfBoard);
						fwrite(&IsLimitP2N1, sizeof(bool), 1, FileOfBoard);
						fwrite(&IsLimitP2N2, sizeof(bool), 1, FileOfBoard);

						fwrite(&DiceVar, sizeof(int), 1, FileOfBoard);

						fwrite(&count, sizeof(int), 1, FileOfBoard);

						fwrite(&iP1, sizeof(int), 1, FileOfBoard);
						fwrite(&iP2, sizeof(int), 1, FileOfBoard);

						fwrite(&User_operation, sizeof(User_operation), 1, FileOfBoard);
						//----------------------------------------------------------------------
						//structs---------------------------

						fwrite(&btn_P1Nut1, sizeof(struct button), 1, FileOfBoard);
						fwrite(&btn_P1Nut2, sizeof(struct button), 1, FileOfBoard);
						fwrite(&btn_P2Nut1, sizeof(struct button), 1, FileOfBoard);
						fwrite(&btn_P2Nut2, sizeof(struct button), 1, FileOfBoard);

						fwrite(&P1Nut1.x, sizeof(int), 1, FileOfBoard);
						fwrite(&P1Nut1.y, sizeof(int), 1, FileOfBoard);

						fwrite(&P1Nut2.x, sizeof(int), 1, FileOfBoard);
						fwrite(&P1Nut2.y, sizeof(int), 1, FileOfBoard);

						fwrite(&P2Nut1.x, sizeof(int), 1, FileOfBoard);
						fwrite(&P2Nut1.y, sizeof(int), 1, FileOfBoard);

						fwrite(&P2Nut2.x, sizeof(int), 1, FileOfBoard);
						fwrite(&P2Nut2.y, sizeof(int), 1, FileOfBoard);

						fwrite(CardPlace, sizeof(struct NUT), 9, FileOfBoard);
						fwrite(CarridorPlace, sizeof(struct NUT), 8, FileOfBoard);

						fread(ArrayCardsPlace, sizeof(int), 9, FileOfBoard);

						for (int i = 0; i < 8; i++)fwrite(&(ArrayCarridorsPlace[i][0]), sizeof(int), 1, FileOfBoard);

						for (int i = 0; i < 8; i++) fwrite(&(ArrayCarridorsPlace[i][1]), sizeof(int), 1, FileOfBoard);

						//----------------------------------------
						fseek(FileOfBoard, 0, SEEK_SET);
						fclose(FileOfBoard);
						//-------------------------------------------------------------------------
					}

				//********************************************************


				//2x pic
				if (Tik_COEF)
					al_draw_bitmap(PIC_2X_forDice, 613, 410, 0);
				//--------------------------------
				//Number of cards
				al_draw_textf(font, al_map_rgb(240, 240, 240), CardsP1DistanceFromLeft[COEF], Y_NOCP1_DOORCLOSED, 0, "%d", CardsP1[COEF]);
				al_draw_textf(font, al_map_rgb(240, 240, 240), CardsP1DistanceFromLeft[DICEAGAIN], Y_NOCP1_COEF, 0, "%d", CardsP1[DICEAGAIN]);
				al_draw_textf(font, al_map_rgb(240, 240, 240), CardsP1DistanceFromLeft[LIMIT], Y_NOCP1_LIMIT, 0, "%d", CardsP1[LIMIT]);
				al_draw_textf(font, al_map_rgb(240, 240, 240), CardsP1DistanceFromLeft[DOORCLOSED], Y_NOCP1_DICEAGAIN, 0, "%d", CardsP1[DOORCLOSED]);

				al_draw_textf(font, al_map_rgb(240, 240, 240), CardsP2DistanceFromLeft[COEF], Y_NOCP2_DOORCLOSED, 0, "%d", CardsP2[COEF]);
				al_draw_textf(font, al_map_rgb(240, 240, 240), CardsP2DistanceFromLeft[DICEAGAIN], Y_NOCP2_COEF, 0, "%d", CardsP2[DICEAGAIN]);
				al_draw_textf(font, al_map_rgb(240, 240, 240), CardsP2DistanceFromLeft[LIMIT], Y_NOCP2_LIMIT, 0, "%d", CardsP2[LIMIT]);
				al_draw_textf(font, al_map_rgb(240, 240, 240), CardsP2DistanceFromLeft[DOORCLOSED], Y_NOCP2_DICEAGAIN, 0, "%d", CardsP2[DOORCLOSED]);

				KeepCenterNUMBER(CardsP1DistanceFromLeft, CriterionOfDistanceP1, CardsP1);
				KeepCenterNUMBER(CardsP2DistanceFromLeft, CriterionOfDistanceP2, CardsP2);
				//----------------------------------------------------------------------------------------------------

#pragma region LOGIC
				switch (player_Turn)
				{
				case P1:
					switch (User_operation)
					{
					case CLICKDICE:
						if (Tik_COEF) DiceVar *= 2;
						else
						{
							sw_btnDown = true;
							DiceVar = DiceRand();
							Dice_PIC_VAR = Dice_PIC[DiceVar];
							ConvertToDiceMIM(&DiceVar);
							if (P1Nut1.y == PP1N1_T && P1Nut2.y == PP1N2_T && DiceVar != 3)
							{
								player_Turn = P2;
								User_operation = -1;
								Tik_Dice = false;
								Tik_Player = true;
								IsLimitP1N1 = false;
								IsLimitP1N2 = false;
							}
							else if (P1Nut1.y == PP1N1_T && DiceVar != 3) IsLimitP1N1 = true;
							else if (P1Nut2.y == PP1N2_T && DiceVar != 3) IsLimitP1N2 = true;
							if ((IsLimitP1N1 && IsLimitP1N2) || (!P1N1_IsLive && IsLimitP1N2) || (!P1N2_IsLive && IsLimitP1N1))
							{
								player_Turn = P2;
								User_operation = -1;
								Tik_Dice = false;
								Tik_Player = true;
								IsLimitP1N1 = false;
								IsLimitP1N2 = false;
							}

						}
						User_operation = -1;
						break;
					case CLICKCARD_doorclosed:
						break;
					case CLICKCARD_coef:
						break;
					case CLICKCARD_limit:
						al_flip_display();
						while (1)
						{
							if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) exit(0);
							al_wait_for_event(queue, &event);
							if (al_is_event_queue_empty(queue))
							{
								al_get_mouse_state(&mouseState);

								al_draw_bitmap(MassageForLimitation, 341, 16, 0);
								if (sw_btn(&btn_P2Nut1, &mouseState))
								{
									if (al_mouse_button_down(&mouseState, 1))
									{
										IsLimitP2N1 = true;
										break;
									}
								}
								if (sw_btn(&btn_P2Nut2, &mouseState))
								{
									if (al_mouse_button_down(&mouseState, 1))
									{
										IsLimitP2N2 = true;
										break;
									}
								}
								al_flip_display();
							}
						}
						User_operation = -1;
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
								if (P1Nut1.y == PP1N1_T) DiceVar = 0;
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
									P2Nut2.x = PP2N2_L;
									P2Nut2.y = PP2N2_T;

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
								}
								//--------------------------------------

								//4-move with carridors

								if (CardsP1[DOORCLOSED])
								{
									//	printf("check while1");
									if (IsCarridorPlace(&Player1[0], ArrayCarridorsPlace, false))
									{
										al_draw_bitmap(P1Nut1.picture_Carridor, P1Nut1.x, P1Nut1.y, 0);
										al_flip_display();
										while (1)
										{
											if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) exit(0);
											al_wait_for_event(queue, &event);
											if (al_is_event_queue_empty(queue))
											{
												al_draw_bitmap(NoticeToCarridor, 800, 730, 0);
												al_draw_bitmap(NoticeToCarridor_ProgressBar, X_ProgressBar, 801, 0);
												al_get_mouse_state(&mouseState);
												if (sw_btn(&btn_CANCEL_NoticeToCarridor, &mouseState))
												{
													if (al_mouse_button_down(&mouseState, 1))
													{
														Tik_Opinion_ForCarridor = true;
														break;
													}
												}
												if (sw_btn(&btn_OK_NoticeToCarridor, &mouseState) || sw_btn(&btn_closeDoor_card_p1, &mouseState))
												{
													if (al_mouse_button_down(&mouseState, 1))
													{
														CardsP1[DOORCLOSED]--;
														Tik_Opinion_ForCarridor = false;
														break;
													}
												}
												if (X_ProgressBar < 1300)
												{
													X_ProgressBar += (0.5);
												}
												else
												{
													X_ProgressBar = 800;
													Tik_Opinion_ForCarridor = true;
													break;
												}
												al_flip_display();
											}
										}
									}
								}

								bool IsCarridor = false;
								if (Tik_Opinion_ForCarridor)
									if (IsCarridorPlace(&Player1[0], ArrayCarridorsPlace, true))
									{
										Tik_Opinion_ForCarridor = true;

										IsCarridor = true;//for move Graphic

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
											P2Nut2.x = PP2N2_L;
											P2Nut2.y = PP2N2_T;

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
							Tik_AGAINDICE = false;
							Tik_COEF = false;
							Tik_LIMIT = false;
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
								if (P1Nut2.y == PP1N2_T) DiceVar = 0;
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
								}
								//--------------------------------------

								//4-move with carridors
								if (CardsP1[DOORCLOSED])
								{
									//	printf("check while1");
									if (IsCarridorPlace(&Player1[1], ArrayCarridorsPlace, false))
									{
										//we can put p1nut1 for picture of p1nut2
										al_draw_bitmap(P1Nut1.picture_Carridor, P1Nut2.x, P1Nut2.y, 0);
										al_flip_display();
										while (1)
										{
											if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) exit(0);
											al_wait_for_event(queue, &event);
											if (al_is_event_queue_empty(queue))
											{
												al_draw_bitmap(NoticeToCarridor, 800, 730, 0);
												al_draw_bitmap(NoticeToCarridor_ProgressBar, X_ProgressBar, 801, 0);
												al_get_mouse_state(&mouseState);
												if (sw_btn(&btn_CANCEL_NoticeToCarridor, &mouseState))
												{
													printf("check cancel btn 2");
													if (al_mouse_button_down(&mouseState, 1))
													{
														Tik_Opinion_ForCarridor = true;
														break;
													}
												}
												if (sw_btn(&btn_OK_NoticeToCarridor, &mouseState) || sw_btn(&btn_closeDoor_card_p1, &mouseState))
												{
													if (al_mouse_button_down(&mouseState, 1))
													{
														printf("check OK btn 2");
														CardsP1[DOORCLOSED]--;
														Tik_Opinion_ForCarridor = false;
														break;
													}
												}
												if (X_ProgressBar < 1300)
												{
													X_ProgressBar += (0.5);
													printf("%f\n", X_ProgressBar);
												}
												else
												{
													X_ProgressBar = 800;
													Tik_Opinion_ForCarridor = true;
													break;
												}
												al_flip_display();
											}
										}
									}
								}

								bool IsCarridor = false;
								if (Tik_Opinion_ForCarridor)
									if (IsCarridorPlace(&Player1[1], ArrayCarridorsPlace, true))
									{
										Tik_Opinion_ForCarridor = true;

										IsCarridor = true;//for move Graphic

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
										}
										//--------------------------------------

									}
								if (IsCarridor) MoveGraphic(Player1[1], &(P1Nut2.x), &(P1Nut2.y));

								//-------------------------------------------
								btn_P1Nut2.X_frist = P1Nut2.x;
								btn_P1Nut2.Y_frist = P1Nut2.y;
								btn_P1Nut2.X_end = P1Nut2.x + PPNW;
								btn_P1Nut2.Y_end = P1Nut2.y + PPNW;

							}
							Tik_AGAINDICE = false;
							Tik_COEF = false;
							Tik_LIMIT = false;
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
						if (Tik_COEF) DiceVar *= 2;
						else
						{
							sw_btnDown = true;
							DiceVar = DiceRand();
							Dice_PIC_VAR = Dice_PIC[DiceVar];
							ConvertToDiceMIM(&DiceVar);
							if (P2Nut1.y == PP2N1_T && P2Nut2.y == PP2N2_T && DiceVar != -3)
							{
								player_Turn = P1;
								User_operation = -1;
								Tik_Dice = false;;
								Tik_Player = true;
								IsLimitP2N1 = false;
								IsLimitP2N2 = false;
							}
							else if (P2Nut1.y == PP2N1_T && DiceVar != -3) IsLimitP2N1 = true;
							else if (P2Nut2.y == PP2N2_T && DiceVar != -3) IsLimitP2N2 = true;
							if (IsLimitP2N1 && IsLimitP2N2 || (!P2N1_IsLive && IsLimitP2N2) || (!P2N2_IsLive && IsLimitP2N1))
							{
								player_Turn = P1;
								User_operation = -1;
								Tik_Dice = false;
								Tik_Player = true;
								IsLimitP2N1 = false;
								IsLimitP2N2 = false;
							}
						}
						User_operation = -1;
						break;
					case CLICKCARD_doorclosed:
						break;
					case CLICKCARD_coef:
						break;
					case CLICKCARD_limit:
						al_flip_display();
						while (1)
						{
							if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) exit(0);
							al_wait_for_event(queue, &event);
							if (al_is_event_queue_empty(queue))
							{
								al_get_mouse_state(&mouseState);

								al_draw_bitmap(MassageForLimitation, 564, 727, 0);
								if (sw_btn(&btn_P1Nut1, &mouseState))
								{
									if (al_mouse_button_down(&mouseState, 1))
									{
										IsLimitP1N1 = true;
										break;
									}
								}
								if (sw_btn(&btn_P1Nut2, &mouseState))
								{
									if (al_mouse_button_down(&mouseState, 1))
									{
										IsLimitP1N2 = true;
										break;
									}
								}
								al_flip_display();
							}
						}
						User_operation = -1;

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
								if (P2Nut1.y == PP2N1_T) DiceVar = 0;
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
								}
								//--------------------------------------

								//4-move with carridors
								if (CardsP2[DOORCLOSED])
								{
									//	printf("check while1");
									if (IsCarridorPlace(&Player2[0], ArrayCarridorsPlace, false))
									{
										//we can put p1nut1 for picture of p1nut2
										al_draw_bitmap(P2Nut2.picture_Carridor, P2Nut1.x, P2Nut1.y, 0);
										al_flip_display();
										while (1)
										{
											if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) exit(0);
											al_wait_for_event(queue, &event);
											if (al_is_event_queue_empty(queue))
											{
												al_draw_bitmap(NoticeToCarridor, 800, 730, 0);
												al_draw_bitmap(NoticeToCarridor_ProgressBar, X_ProgressBar, 801, 0);
												al_get_mouse_state(&mouseState);
												if (sw_btn(&btn_CANCEL_NoticeToCarridor, &mouseState))
												{
													if (al_mouse_button_down(&mouseState, 1))
													{
														Tik_Opinion_ForCarridor = true;
														break;
													}
												}
												if (sw_btn(&btn_OK_NoticeToCarridor, &mouseState) || sw_btn(&btn_closeDoor_card_p2, &mouseState))
												{
													if (al_mouse_button_down(&mouseState, 1))
													{
														CardsP2[DOORCLOSED]--;
														Tik_Opinion_ForCarridor = false;
														break;
													}
												}
												if (X_ProgressBar < 1300)
												{
													X_ProgressBar += (0.5);
												}
												else
												{
													X_ProgressBar = 800;
													Tik_Opinion_ForCarridor = true;
													break;
												}
												al_flip_display();
											}
										}
									}
								}

								bool IsCarridor = false;
								if (Tik_Opinion_ForCarridor)
									if (IsCarridorPlace(&Player2[0], ArrayCarridorsPlace, true))
									{
										Tik_Opinion_ForCarridor = true;

										IsCarridor = true;//for move Graphic

										//2-Hitting
										if (Player2[0] == Player1[0]) {
											Player1[0] = 80;
											P1Nut1.x = PP1N1_L;
											P1Nut1.y = PP1N1_T;

											btn_P1Nut1.X_frist = PP1N1_L;
											btn_P1Nut1.Y_frist = PP1N1_T;
											btn_P1Nut1.X_end = PP1N1_L + PPNW;
											btn_P1Nut1.Y_end = PP1N1_T + PPNW;
										}
										if (Player2[0] == Player1[1]) {
											Player1[1] = 80;
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
										}
										//--------------------------------------

									}
								if (IsCarridor) MoveGraphic(Player2[0], &(P2Nut1.x), &(P2Nut1.y));

								//------------------------------------
								btn_P2Nut1.X_frist = P2Nut1.x;
								btn_P2Nut1.Y_frist = P2Nut1.y;
								btn_P2Nut1.X_end = P2Nut1.x + PPNW;
								btn_P2Nut1.Y_end = P2Nut1.y + PPNW;
							}
							Tik_AGAINDICE = false;
							Tik_COEF = false;
							Tik_LIMIT = false;
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
								if (P2Nut2.y == PP2N2_T) DiceVar = 0;
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
								}
								//--------------------------------------

								//4-move with carridors
								if (CardsP2[DOORCLOSED])
								{
									//	printf("check while1");
									if (IsCarridorPlace(&Player2[1], ArrayCarridorsPlace, false))
									{
										//we can put p1nut1 for picture of p1nut2
										al_draw_bitmap(P2Nut2.picture_Carridor, P2Nut2.x, P2Nut2.y, 0);
										al_flip_display();
										while (1)
										{
											if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) exit(0);
											al_wait_for_event(queue, &event);
											if (al_is_event_queue_empty(queue))
											{
												al_draw_bitmap(NoticeToCarridor, 800, 730, 0);
												al_draw_bitmap(NoticeToCarridor_ProgressBar, X_ProgressBar, 801, 0);
												al_get_mouse_state(&mouseState);
												if (sw_btn(&btn_CANCEL_NoticeToCarridor, &mouseState))
												{
													if (al_mouse_button_down(&mouseState, 1))
													{
														Tik_Opinion_ForCarridor = true;
														break;
													}
												}
												if (sw_btn(&btn_OK_NoticeToCarridor, &mouseState) || sw_btn(&btn_closeDoor_card_p2, &mouseState))
												{
													if (al_mouse_button_down(&mouseState, 1))
													{
														CardsP2[DOORCLOSED]--;
														Tik_Opinion_ForCarridor = false;
														break;
													}
												}
												if (X_ProgressBar < 1300)
												{
													X_ProgressBar += (0.5);
												}
												else
												{
													X_ProgressBar = 800;
													Tik_Opinion_ForCarridor = true;
													break;
												}
												al_flip_display();
											}
										}
									}
								}

								bool IsCarridor = false;
								if (Tik_Opinion_ForCarridor)
									if (IsCarridorPlace(&Player2[1], ArrayCarridorsPlace, true))
									{
										Tik_Opinion_ForCarridor = true;

										IsCarridor = true;//for move Graphic

										//2-Hitting
										if (Player2[1] == Player1[0]) {
											Player1[0] = 80;
											P1Nut1.x = PP1N1_L;
											P1Nut1.y = PP1N1_T;

											btn_P1Nut1.X_frist = PP1N1_L;
											btn_P1Nut1.Y_frist = PP1N1_T;
											btn_P1Nut1.X_end = PP1N1_L + PPNW;
											btn_P1Nut1.Y_end = PP1N1_T + PPNW;
										}
										if (Player2[1] == Player1[1]) {
											Player1[1] = 80;
											P1Nut2.x = PP1N2_L;
											P1Nut2.y = PP1N2_T;

											btn_P1Nut2.X_frist = PP1N2_L;
											btn_P1Nut2.Y_frist = PP1N2_T;
											btn_P1Nut2.X_end = PP1N2_L + PPNW;
											btn_P1Nut2.Y_end = PP1N2_T + PPNW;
										}
										//--------------------------------

										//3-Become add a Lucky Card
										if (IsLuckyCardPlace(Player2[1], ArrayCardsPlace))
										{
											CardChoosed = CardRand();
											CardsP2[CardChoosed]++;
										}
										//--------------------------------------

									}
								if (IsCarridor) MoveGraphic(Player2[1], &(P2Nut2.x), &(P2Nut2.y));

								//-------------------------------
								btn_P2Nut2.X_frist = P2Nut2.x;
								btn_P2Nut2.Y_frist = P2Nut2.y;
								btn_P2Nut2.X_end = P2Nut2.x + PPNW;
								btn_P2Nut2.Y_end = P2Nut2.y + PPNW;
							}
							Tik_AGAINDICE = false;
							Tik_COEF = false;
							Tik_LIMIT = false;
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

				if (Player1[0] == 40)
				{
					P1Nut1.x = 810;
					P1Nut1.y = 1300;
					P1N1_IsLive = false;
					IsLimitP1N1 = true;
					Player1[0] = -1;
				}
				if (Player1[1] == 40)
				{
					P1Nut2.x = 810;
					P1Nut2.y = 1300;
					P1N2_IsLive = false;
					IsLimitP1N2 = true;
					Player1[1] = -1;
				}
				if (Player2[0] == 40)
				{
					P2Nut1.x = 810;
					P2Nut1.y = 1300;
					P2N1_IsLive = false;
					IsLimitP2N1 = true;
					Player2[0] = -1;
				}
				if (Player2[1] == 40)
				{
					P2Nut2.x = 810;
					P2Nut2.y = 1300;
					P2N2_IsLive = false;
					IsLimitP2N2 = true;
					Player2[1] = -1;
				}
#pragma endregion
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
		if (Player1[0] == -1 && Player1[1] == -1)
		{
			printf("***************************   Hoora P1   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11");
			//Vars///////////////////////////////////////////////////////////////////////
			Player1[0] = 0;
			Player1[1] = 0;
			Player2[0] = 80;
			Player2[1] = 80;

			CardsP1[0] = CardsP1_Assumption[0];
			CardsP1[1] = CardsP1_Assumption[1];
			CardsP1[2] = CardsP1_Assumption[2];
			CardsP1[3] = CardsP1_Assumption[3];

			CardsP2[0] = CardsP2_Assumption[0];
			CardsP2[1] = CardsP2_Assumption[1];
			CardsP2[2] = CardsP2_Assumption[2];
			CardsP2[3] = CardsP2_Assumption[3];

			Tik_Dice = false;
			Tik_Nut = false;
			Tik_Player = true;

			Tik_AGAINDICE = false;
			Tik_COEF = false;
			Tik_LIMIT = false;

			P1N1_IsLive = true;
			P1N2_IsLive = true;
			P2N1_IsLive = true;
			P2N2_IsLive = true;

			one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form = false;

			one_click_btn_DICEAGAIN_CARD_p1 = true;
			one_click_btn_DICEAGAIN_CARD_p2 = true;

			one_click_btn_COEF_CARD_p1 = true;
			one_click_btn_COEF_CARD_p2 = true;

			one_click_btn_LIMIT_CARD_p1 = true;
			one_click_btn_LIMIT_CARD_p2 = true;

			turn = 1;

			//variable LOGIC-------------------------					
			player_Turn = P1;//turn of players							

			IsDoorClosed = 0;

			CoefDice = 1;

			sw_AgainDice = 0;

			playerSW = 1;

			IsLimitP1N1 = false;
			IsLimitP1N2 = false;
			IsLimitP2N1 = false;
			IsLimitP2N2 = false;

			DiceVar = 0;

			count = 0;

			iP1 = 0;
			iP2 = 0;

			CardChoosed;

			User_operation = -1;
			//---------------------------
			//structs

			btn_P1Nut1.X_frist = PP1N1_L;
			btn_P1Nut1.Y_frist = PP1N1_T;
			btn_P1Nut1.X_end = PP1N1_L + PPNW;
			btn_P1Nut1.Y_end = PP1N1_T + PPNW;
			btn_P1Nut1.sw_Link = NULL;

			btn_P1Nut2.X_frist = PP1N2_L;
			btn_P1Nut2.Y_frist = PP1N2_T;
			btn_P1Nut2.X_end = PP1N2_L + PPNW;
			btn_P1Nut2.Y_end = PP1N2_T + PPNW;
			btn_P1Nut2.sw_Link = NULL;

			btn_P2Nut1.X_frist = PP2N1_L;
			btn_P2Nut1.Y_frist = PP2N1_T;
			btn_P2Nut1.X_end = PP2N1_L + PPNW;
			btn_P2Nut1.Y_end = PP2N1_T + PPNW;
			btn_P2Nut1.sw_Link = NULL;

			btn_P2Nut2.X_frist = PP2N2_L;
			btn_P2Nut2.Y_frist = PP2N2_T;
			btn_P2Nut2.X_end = PP2N2_L + PPNW;
			btn_P2Nut2.Y_end = PP2N2_T + PPNW;
			btn_P2Nut2.sw_Link = NULL;


			//---------------------------
			P1Nut1.x = PP1N1_L;
			P1Nut1.y = PP1N1_T;

			P1Nut2.x = PP1N2_L;
			P1Nut2.y = PP1N2_T;

			P2Nut1.x = PP2N1_L;
			P2Nut1.y = PP2N1_T;

			P2Nut2.x = PP2N2_L;
			P2Nut2.y = PP2N2_T;
			//End////////////////////////////////////////////////////////////////////////

			pages_sw = FristMenu;
			Is_StartOfBackToMenu = true;


		}
		else if (Player2[0] == -1 && Player2[1] == -1)
		{
			printf("***************************   Hoora P2   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!22");
			//Vars///////////////////////////////////////////////////////////////////////
			Player1[0] = 0;
			Player1[1] = 0;
			Player2[0] = 80;
			Player2[1] = 80;

			CardsP1[0] = CardsP1_Assumption[0];
			CardsP1[1] = CardsP1_Assumption[1];
			CardsP1[2] = CardsP1_Assumption[2];
			CardsP1[3] = CardsP1_Assumption[3];

			CardsP2[0] = CardsP2_Assumption[0];
			CardsP2[1] = CardsP2_Assumption[1];
			CardsP2[2] = CardsP2_Assumption[2];
			CardsP2[3] = CardsP2_Assumption[3];

			Tik_Dice = false;
			Tik_Nut = false;
			Tik_Player = true;

			Tik_AGAINDICE = false;
			Tik_COEF = false;
			Tik_LIMIT = false;

			P1N1_IsLive = true;
			P1N2_IsLive = true;
			P2N1_IsLive = true;
			P2N2_IsLive = true;

			one_click_btn_TWEPERSON_To_buttons_continueANDnew_Form = false;

			one_click_btn_DICEAGAIN_CARD_p1 = true;
			one_click_btn_DICEAGAIN_CARD_p2 = true;

			one_click_btn_COEF_CARD_p1 = true;
			one_click_btn_COEF_CARD_p2 = true;

			one_click_btn_LIMIT_CARD_p1 = true;
			one_click_btn_LIMIT_CARD_p2 = true;

			turn = 1;

			//variable LOGIC-------------------------					
			player_Turn = P1;//turn of players							

			IsDoorClosed = 0;

			CoefDice = 1;

			sw_AgainDice = 0;

			playerSW = 1;

			IsLimitP1N1 = false;
			IsLimitP1N2 = false;
			IsLimitP2N1 = false;
			IsLimitP2N2 = false;

			DiceVar = 0;

			count = 0;

			iP1 = 0;
			iP2 = 0;

			CardChoosed;

			User_operation = -1;
			//---------------------------
			//structs

			btn_P1Nut1.X_frist = PP1N1_L;
			btn_P1Nut1.Y_frist = PP1N1_T;
			btn_P1Nut1.X_end = PP1N1_L + PPNW;
			btn_P1Nut1.Y_end = PP1N1_T + PPNW;
			btn_P1Nut1.sw_Link = NULL;

			btn_P1Nut2.X_frist = PP1N2_L;
			btn_P1Nut2.Y_frist = PP1N2_T;
			btn_P1Nut2.X_end = PP1N2_L + PPNW;
			btn_P1Nut2.Y_end = PP1N2_T + PPNW;
			btn_P1Nut2.sw_Link = NULL;

			btn_P2Nut1.X_frist = PP2N1_L;
			btn_P2Nut1.Y_frist = PP2N1_T;
			btn_P2Nut1.X_end = PP2N1_L + PPNW;
			btn_P2Nut1.Y_end = PP2N1_T + PPNW;
			btn_P2Nut1.sw_Link = NULL;

			btn_P2Nut2.X_frist = PP2N2_L;
			btn_P2Nut2.Y_frist = PP2N2_T;
			btn_P2Nut2.X_end = PP2N2_L + PPNW;
			btn_P2Nut2.Y_end = PP2N2_T + PPNW;
			btn_P2Nut2.sw_Link = NULL;


			//---------------------------
			P1Nut1.x = PP1N1_L;
			P1Nut1.y = PP1N1_T;

			P1Nut2.x = PP1N2_L;
			P1Nut2.y = PP1N2_T;

			P2Nut1.x = PP2N1_L;
			P2Nut1.y = PP2N1_T;

			P2Nut2.x = PP2N2_L;
			P2Nut2.y = PP2N2_T;
			//End////////////////////////////////////////////////////////////////////////

			pages_sw = FristMenu;
			Is_StartOfBackToMenu = true;

		}
	}
#pragma region Destroying

	al_uninstall_keyboard();
	al_uninstall_mouse();
	al_uninstall_system();

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

	al_destroy_bitmap(char_frame_p1);
	al_destroy_bitmap(char_frame_p2);

	al_destroy_bitmap(charactors_PIC[char1]);
	al_destroy_bitmap(charactors_PIC[char2]);
	al_destroy_bitmap(charactors_PIC[char3]);
	al_destroy_bitmap(charactors_PIC[char4]);
	al_destroy_bitmap(charactors_PIC[char5]);
	al_destroy_bitmap(charactors_PIC[char6]);
	al_destroy_bitmap(charactors_PIC[char7]);
	al_destroy_bitmap(charactors_PIC[char8]);
	al_destroy_bitmap(charactors_PIC[char9]);

	al_destroy_bitmap(P1Nut1.picture);
	al_destroy_bitmap(P1Nut1.picture_Carridor);
	al_destroy_bitmap(P1Nut2.picture);
	al_destroy_bitmap(P2Nut1.picture);
	al_destroy_bitmap(P2Nut2.picture);
	al_destroy_bitmap(P2Nut2.picture_Carridor);

	al_destroy_bitmap(GuideIcon);
	al_destroy_bitmap(RefreshIcon);
	al_destroy_bitmap(Menu_InTheBoard_Icon);
	al_destroy_bitmap(MenuFramePic);
	al_destroy_bitmap(Save_Icon);

	al_destroy_bitmap(char_frame_p1);
	al_destroy_bitmap(char_frame_p2);

	al_destroy_bitmap(startgame_PIC);
	al_destroy_bitmap(Formcontinue_PIC);

	al_destroy_bitmap(Formcontinue_PIC);

	al_destroy_bitmap(MenuInTheBoard_PIC);

	al_destroy_bitmap(RefreshInTheBoard_PIC);

	al_destroy_bitmap(ContinueAndNewButtonsForm_PIC);

	al_destroy_bitmap(Guid_page[0]);
	al_destroy_bitmap(Guid_page[1]);
	al_destroy_bitmap(Guid_page[2]);
	al_destroy_bitmap(Guid_page[3]);
	al_destroy_bitmap(Guid_page[4]);
	al_destroy_bitmap(Guid_page[5]);

	al_destroy_bitmap(GuidVar);

	al_destroy_bitmap(CarridorPlace_PIC);
	al_destroy_bitmap(CardLuckPlace_PIC);





	al_destroy_bitmap(Board_PIC);

	al_destroy_bitmap(FristMenu_Form_PIC);
#pragma endregion
	exit(0);
}