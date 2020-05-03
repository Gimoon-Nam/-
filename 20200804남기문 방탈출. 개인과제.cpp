#include <stdio.h>
#include <bangtal.h>
SceneID start, mainhall, s1_right, s1_left, s2_left, s2_right, s2_right_chess, s3_left, s3_right_hidden, ending1, ending2, ending3, ending4;
ObjectID
//start
start_game, end_game,
//main stage
main_door_left, main_door_right, main_rd_2, main_record, main_book, main_fire, record_red, record_yellow, record_green, battery_record, key_s1l, key_s2r, key_s3l, key_s3r, door_exit, key_hidden,
//stage1 right
s1r_door, s1r_picture, s1r_picture_changed, s1r_mirror, s1r_candle, s1r_bone, s1r_drawer, s1r_clock, s1r_drawer2, s1r_book, s1r_paper1, s1r_paper2, s1r_paper3,
//stage1 left
s1l_door, s1l_sinkdrawer, s1l_play1, s1l_play2, s1l_play3, s1l_play4, s1l_play5, s1l_play8,
//stage2 left
s2l_door, s2l_clock, s2l_drawer, s2l_picture1, s2l_picture2, s2l_picture3, s2l_picture4, s2l_picture5, s2l_book, s2l_bookcase, s2l_board,
//stage2 right
s2r_door, s2r_book_RU, s2r_book_RD, s2r_book_LU, s2r_book_LD, s2r_drawer, s2r_paper, s2r_clock, s2r_chess,
//stage2 right_chess
s2r_chess_door, chess_queen1, chess_queen2, chess_queen3, chess_queen4, chess_queen5, chess_queen6, chess_queen7, chess_queen8,
//stage3 left
s3l_door, s3l_book, s3l_handle, s3l_room,
//stage3 right
s3r_door, s3r_book1, s3r_book2, s3r_book3, s3r_book4, s3r_book5, s3r_key,
//Ending
ending_1, ending1_exit, ending_2, ending2_exit, ending_3, ending3_exit, ending_4, ending4_exit
;
SoundID start_BGM, stage1_BGM, stage2_BGM, chess_BGM, stage3_BGM, lock, door,
s1l_1, s1l_2, s1l_3, s1l_4, s1l_5, s1l_8;

bool record = false, door_s1_left = true, door_s2_right = true, door_s3_left = true, door_s3_right = true,
s1_right_light = true, p_s1_right_drawer1 = true, p_s1_right_drawer2 = true,
p_s1_left_sink = true,
p_s2_left_drawer1 = true,
p_s2_right_drawer1 = true,
p_s3_left_handle = true,
s1_right_helper = true,
//QUIZ
s1rQ = true, s1lQ = true, s2lQ = true, s2rQ_chess = true, s2rQ_book = true, s2rQ_chess_clear = true, s2rQ_book_clear = true
;
int
queen1X = 505, queen1Y = 350,
queen2X = 487, queen2Y = 329,
queen3X = 471, queen3Y = 308,
queen4X = 453, queen4Y = 283,
queen5X = 426, queen5Y = 258,
queen6X = 400, queen6Y = 233,
queen7X = 374, queen7Y = 208,
queen8X = 348, queen8Y = 183;

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown == true) {
		showObject(object);
	}
	return object;
}

char s1_r[20], s1_l[20], s2_r[20], s2_l[20], s3_r[20], s3_l[20];

void game_start() {

	/* HINT!!

	sprintf_s(s1_l, "위대의 좌측방");
	sprintf_s(s1_r, "위대의 우측방");
	sprintf_s(s2_l, "오만의 좌측방");
	sprintf_s(s2_r, "오만의 우측방");
	sprintf_s(s3_l, "슬픔의 좌측방");*/
	sprintf_s(s3_r, "제작자의 방");

	//메인화면
	start = createScene("Main Screen", "main.png");
	//메인홀
	mainhall = createScene("mainhall", "stage all_main_1.png");
	s1_right = createScene(s1_r, "stage1_right_1.png");
	s1_left = createScene(s1_l, "stage1_left_1.png");
	//stage2
	s2_left = createScene(s2_l, "stage2_left_2.png");
	s2_right = createScene(s2_r, "stage2_right_1.png");
	s2_right_chess = createScene("", "s2_right_chess.png");
	//stage3
	s3_left = createScene(s3_l, "stage3_left_1.png");
	s3_right_hidden = createScene(s3_r, "stage3_right_1.png");
	//엔딩
	ending1 = createScene("Ending 1", "stage_ending1.png");
	ending2 = createScene("Ending 2", "stage_ending2.png");
	ending3 = createScene("Ending 3", "stage_ending3.png");
	ending4 = createScene("Special Ending", "stage_ending4.png");
}

void object_create() {
	//start
	start_game = createObject("start.png", start, 590, 70, true);
	end_game = createObject("end.png", start, 590, 20, true);

	//main hall
	main_door_left = createObject("main_ld_117,501.png", mainhall, 117, 218, true);
	main_door_right = createObject("main_rd_936,460.png", mainhall, 936, 260, true);
	main_rd_2 = createObject("main_rd_2.png", mainhall, 936, 259, true);
	main_record = createObject("main_record_316,549.png", mainhall, 316, 170, true);
	main_book = createObject("main_book_1002,577.png", mainhall, 1002, 142, true);
	main_fire = createObject("main_fire_691,483.png", mainhall, 691, 236, true);
	door_exit = createObject("door_back.png", mainhall, 590, 20, false);
	scaleObject(door_exit, 0.8f);

	//소지 아이템
	record_red = createObject("record_red.png", start, 0, 0, false);
	record_yellow = createObject("record_yellow.png", start, 0, 0, false);
	record_green = createObject("record_green.png", start, 0, 0, false);
	battery_record = createObject("battery_record.png", start, 0, 0, false);
	key_s1l = createObject("key.png", start, 0, 0, false);
	key_s2r = createObject("key.png", start, 0, 0, false);
	key_s3l = createObject("key.png", start, 0, 0, false);
	key_s3r = createObject("key_s3r.png", start, 0, 0, false);
	key_hidden = createObject("key_hidden.png", start, 0, 0, false);

	//s1_right
	s1r_door = createObject("s1_right_door_982,435.png", s1_right, 982, 284, true);
	s1r_picture = createObject("s1_right_picture_390,334.png", s1_right, 390, 385, true);
	s1r_picture_changed = createObject("s1_right_picture_rasputin_390,334.png", s1_right, 390, 385, false);
	s1r_mirror = createObject("s1_right_mirror_78,441.png", s1_right, 78, 278, true);
	s1r_candle = createObject("s1_right_candle_383,518.png", s1_right, 383, 201, true);
	s1r_bone = createObject("s1_right_bone_26,677.png", s1_right, 26, 42, true);
	s1r_drawer = createObject("s1_right_drawer_185,602.png", s1_right, 185, 117, true);
	s1r_clock = createObject("s1_right_clock_222,326.png", s1_right, 222, 393, true);
	s1r_drawer2 = createObject("s1_right_drawer2_1090,685.png", s1_right, 1090, 34, true);
	s1r_book = createObject("s1_right_book_515,525.png", s1_right, 515, 194, true);
	s1r_paper1 = createObject("s1_right_paper1_593,659.png", s1_right, 593, 60, true);
	s1r_paper2 = createObject("s1_right_paper2_900,706.png", s1_right, 900, 13, true);
	s1r_paper3 = createObject("s1_right_paper3_1008,711.png", s1_right, 1008, 8, true);
	
	//s1_left
	s1l_door = createObject("s1_left_door_0,647.png", s1_left, 0, 72, true);
	s1l_sinkdrawer = createObject("s1_left_sinkdrawer_581,559.png", s1_left, 581, 160, true);
	s1l_play1 = createObject("s1_left_play1_1026,137.png", s1_left, 1026, 582, true);
	s1l_play2 = createObject("s1_left_play2_1099,509.png", s1_left, 1099, 210, true);
	s1l_play3 = createObject("s1_left_play3_232,455.png", s1_left, 232, 264, true);
	s1l_play4 = createObject("s1_left_play4_648,287.png", s1_left, 648, 432, true);
	s1l_play5 = createObject("s1_left_play5_1018,321.png", s1_left, 1018, 398, true);
	s1l_play8 = createObject("s1_left_play8_836,359.png", s1_left, 836, 360, true);

	//s2_left
	s2l_door = createObject("door_back.png", s2_left, 590, 20, true);
	scaleObject(s2l_door, 0.8f);
	s2l_clock = createObject("s2_left_clock_415,420.png", s2_left, 415, 299, true);
	s2l_drawer = createObject("s2_left_drawer_1052,510.png", s2_left, 1052, 209, true);
	s2l_picture1 = createObject("s2_left_picture1_666,395.png", s2_left, 666, 324, true);
	s2l_picture2 = createObject("s2_left_picture2_749,393.png", s2_left, 749, 326, true);
	s2l_picture3 = createObject("s2_left_picture3_826,387.png", s2_left, 826, 332, true);
	s2l_picture4 = createObject("s2_left_picture4_754,283.png", s2_left, 754, 436, true);
	s2l_picture5 = createObject("s2_left_picture5_160,289.png", s2_left, 160, 430, true);
	s2l_book = createObject("s2_left_book_721,665.png", s2_left, 721, 54, true);
	s2l_bookcase = createObject("s2_left_bookcase_1052,333.png", s2_left, 1052, 386, true);
	s2l_board = createObject("s2_left_board_174,497.png", s2_left, 174, 222, true);

	//s2_right
	s2r_door = createObject("door_back.png", s2_right, 590, 20, true);
	scaleObject(s2r_door, 0.8f);
	s2r_book_RU = createObject("s2_right_book_RU_227,250.png", s2_right, 227, 469, true);
	s2r_book_RD = createObject("s2_right_book_RD_233,374.png", s2_right, 233, 345, true);
	s2r_book_LU = createObject("s2_right_book_LU_14,207.png", s2_right, 14, 512, true);
	s2r_book_LD = createObject("s2_right_book_LD_15,414.png", s2_right, 15, 305, true);
	s2r_drawer = createObject("s2_right_drawer_909,556.png", s2_right, 909, 163, true);
	s2r_paper = createObject("s2_right_paper_616,429.png", s2_right, 616, 290, true);
	s2r_clock = createObject("s2_right_clock_1015,371.png", s2_right, 1015, 348, true);
	s2r_chess = createObject("s2r_chess.png", s2_right, 215, 40, true);

	//s2_right_chess
	s2r_chess_door = createObject("door_back.png", s2_right_chess, 590, 20, true);
	scaleObject(s2r_chess_door, 0.8f);
	chess_queen1 = createObject("chess_queen.png", s2_right_chess, queen1X, queen1Y, true);
	chess_queen2 = createObject("chess_queen.png", s2_right_chess, queen2X, queen2Y, true);
	chess_queen3 = createObject("chess_queen.png", s2_right_chess, queen3X, queen3Y, true);
	chess_queen4 = createObject("chess_queen.png", s2_right_chess, queen4X, queen4Y, true);
	chess_queen5 = createObject("chess_queen.png", s2_right_chess, queen5X, queen5Y, true);
	chess_queen6 = createObject("chess_queen.png", s2_right_chess, queen6X, queen6Y, true);
	chess_queen7 = createObject("chess_queen.png", s2_right_chess, queen7X, queen7Y, true);
	chess_queen8 = createObject("chess_queen.png", s2_right_chess, queen8X, queen8Y, true);

	//s3_left
	s3l_door = createObject("door_back.png", s3_left, 590, 20, true);
	scaleObject(s3l_door, 0.8f);
	s3l_book = createObject("s3_left_book_1010,372.png", s3_left, 1010, 347, true);
	s3l_handle = createObject("s3_left_handle_20,696.png", s3_left, 20, 23, true);
	s3l_room = createObject("s3_left_room_411,595.png", s3_left, 411, 124, true);

	//s3_right_hidden
	s3r_door = createObject("door_back.png", s3_right_hidden, 590, 20, true);
	scaleObject(s3r_door, 0.8f);
	s3r_book1 = createObject("s3_right_book_1_238,291.png", s3_right_hidden, 238, 428, true);
	s3r_book2 = createObject("s3_right_book_2_383,282.png", s3_right_hidden, 384, 437, true);
	s3r_book3 = createObject("s3_right_book_3_515,280.png", s3_right_hidden, 515, 439, true);
	s3r_book4 = createObject("s3_right_book_4_651,316.png", s3_right_hidden, 651, 403, true);
	s3r_book5 = createObject("s3_right_book_5_851,551.png", s3_right_hidden, 851, 168, true);
	s3r_key = createObject("s3_right_key_439,625.png", s3_right_hidden, 439, 94, true);

	//Ending
	ending_1 = createObject("ending_1_45,580.png", ending1, 45, 139, true);
	ending1_exit = createObject("end.png", ending1, 590, 50, false);
	ending_2 = createObject("ending_2_39,602.png", ending2, 39, 117, true);
	ending2_exit = createObject("end.png", ending2, 590, 50, false);
	ending_3 = createObject("ending_3_42,608.png", ending3, 43, 111, true);
	ending3_exit = createObject("end.png", ending3, 590, 50, false);
	ending_4 = createObject("ending_4_37,599.png", ending4, 37, 120, true);
	ending4_exit = createObject("end.png", ending4, 590, 50, false);
}

void sound_create() {
	start_BGM = createSound("Intro.wav");
	lock = createSound("lock.mp3");
	door = createSound("door.mp3");
//s1_main
	stage1_BGM = createSound("BGM.mp3");

//s1_left
	s1l_1 = createSound("1.mp3");
	s1l_2 = createSound("2.wav");
	s1l_3 = createSound("3.mp3");
	s1l_4 = createSound("4.mp3");
	s1l_5 = createSound("5.mp3");
	s1l_8 = createSound("8.mp3");

//s2_main
	stage2_BGM = createSound("stage2_BGM.mp3");
//s2_chess
	chess_BGM = createSound("chess_BGM.mp3");
//s3_main
	stage3_BGM = createSound("stage3_BGM.mp3");
}

int a = 0, b = 1, c = 1, s1r1 = 0, s1r2 = 0, s1l1 = 0, s2l1 = 0, s2r1 = 0, s2r2 = 0, hint = 0, hint_num = 0, exit_door = 0;

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {

	//start
	if (object == end_game) {
		endGame();
	}
	else if (object == start_game) {
		stopSound(start_BGM);
		enterScene(mainhall);
		playSound(stage1_BGM, true);
	}
	//main hall
	else if (object == main_door_right) {
		if (b == 1) {
			enterScene(s1_right);
		}
		else if (b == 2) {
			if (door_s2_right == true) {
				if (getHandObject() == key_s2r) {
					playSound(door);
					showMessage("문이 열렸다");
					door_s2_right = false;
					dropObject(key_s2r);
					hideObject(key_s2r);
				}
				else {
					showMessage("문이 잠겨있다");
				}
			}
			else {
				enterScene(s2_right);
			}
		}
		else if (b == 3) {
			if (door_s3_right == true) {
				if (getHandObject() == key_s3r) {
					playSound(door);
					showMessage("문이 열렸다");
					door_s3_right = false;
					dropObject(key_s3r);
					hideObject(key_s3r);
				}
				else {
					showMessage("문이 잠겨있다");
				}
			}
			else {
				enterScene(s3_right_hidden);
			}
		}
	}
	else if (object == main_door_left) {
		if (b == 1) {
			if (door_s1_left == true) {
				if (getHandObject() == key_s1l) {
					playSound(door);
					showMessage("문이 열렸다");
					door_s1_left = false;
					dropObject(key_s1l);
					hideObject(key_s1l);
				}
				else {
					showMessage("문이 잠겨있다");
				}
			}
			else {
				enterScene(s1_left);
			}
		}
		else if (b == 2) {
			enterScene(s2_left);
		}
		else if (b == 3) {
			if (door_s3_left == true) {
				if (getHandObject() == key_s3l) {
					playSound(door);
					showMessage("문이 열렸다");
					door_s3_left = false;
					dropObject(key_s3l);
					hideObject(key_s3l);
				}
				else {
					showMessage("문이 잠겨있다");
				}
			}
			else {
				enterScene(s3_left);
			}
		}
	}
	else if (object == main_book) {
		showMessage("초청, 보석, 파티, 죽음"); //1425
	}
	else if (object == main_record) {
		if (getHandObject() == battery_record) {
			record = true;
			showMessage("레코드판을 작동시켰다.");
			dropObject(battery_record);
			hideObject(battery_record);
		}
		if (record == true) {
			if (b == 1) {
				if (getHandObject() == record_yellow) {
					dropObject(record_yellow);
					hideObject(record_yellow);
					pickObject(record_red);
					stopSound(stage1_BGM);
					playSound(stage2_BGM, true);
					b = 2;
				}
				else if (getHandObject() == record_green) {
					dropObject(record_green);
					hideObject(record_green);
					pickObject(record_red);
					stopSound(stage1_BGM);
					playSound(stage3_BGM, true);
					b = 3;
				}
				else {
					showMessage("교체할 레코드판을 손에 들고있지 않다.");
				}
			}
			else if (b == 2) {
				if (getHandObject() == record_red) {
					dropObject(record_red);
					hideObject(record_red);
					pickObject(record_yellow);
					stopSound(stage2_BGM);
					playSound(stage1_BGM, true);
					b = 1;
				}
				else if (getHandObject() == record_green) {
					dropObject(record_green);
					hideObject(record_green);
					pickObject(record_yellow);
					stopSound(stage2_BGM);
					playSound(stage3_BGM, true);
					b = 3;
				}
				else {
					showMessage("교체할 레코드판을 손에 들고있지 않다.");
				}
			}
			else if (b == 3) {
				if (getHandObject() == record_red) {
					dropObject(record_red);
					hideObject(record_red);
					pickObject(record_green);
					stopSound(stage3_BGM);
					playSound(stage1_BGM, true);
					b = 1;
				}
				else if (getHandObject() == record_yellow) {
					dropObject(record_yellow);
					hideObject(record_yellow);
					pickObject(record_green);
					stopSound(stage3_BGM);
					playSound(stage2_BGM, true);
					b = 2;
				}
				else {
					showMessage("교체할 레코드판을 손에 들고있지 않다.");
				}
			}
		}
		else {
			showMessage("레코드판이 동작하지 않는것 같다");
		}
	}
	else if (object == door_exit) {
		if (exit_door == 1) {
			if (b == 1) {
				enterScene(ending1);
			}
			else {
				showMessage("다른 스테이지의 문이야");
			}
		}
		else if (exit_door == 2) {
			if (b == 2) {
				enterScene(ending2);
			}
			else {
				showMessage("다른 스테이지의 문이야");
			}
		}
		else if (exit_door == 3) {
			if (b == 3) {
				enterScene(ending3);
			}
			else {
				showMessage("다른 스테이지의 문이야");
			}
		}
		else if (exit_door == 4) {
			if (getHandObject() == key_hidden) {
				dropObject(key_hidden);
				hideObject(key_hidden);
				enterScene(ending4);
			}
			else {
				showMessage("열쇠가 필요해");
			}

		}
	}
	//s1_right
	else if (object == s1r_door) {
		enterScene(mainhall);
	}
	else if (object == s1r_candle) {
		s1_right_light = !s1_right_light;
		if (s1_right_light == true) {
			setSceneLight(s1_right, 1.0f);
			if (s1_right_helper == true) {
				hideObject(s1r_picture_changed);
				showObject(s1r_picture);
			}
		}
		else {
			setSceneLight(s1_right, 0.2f);
			if (s1_right_helper == true) {
				hideObject(s1r_picture);
				showObject(s1r_picture_changed);
			}
		}
	}
	else if (object == s1r_picture_changed) {
		if (s1_right_light == false) {
			if (hint == 0) {
				showMessage("필요할때 내게 찾아오면 도움을 줄게 \n 하지만 내게 너무 의지하진 마");
				hint = 1;
			}
			else if (hint == 1) {
				if (s1rQ == true) {
					showMessage("방에 떨어진 3개의 종이와, \n mainhall의 책장의 힌트를 잘 생각해봐.");
					hint_num += 1;
					s1rQ = false;
				}
				else {
					showMessage("방에 떨어진 3개의 종이와, \n mainhall의 책장의 힌트를 잘 생각해봐.");
				}			
			}
			else if (hint == 2) {
				if (s1lQ == true) {
					showMessage("음계상에서 1은 '도'겠지? \n 오른쪽 위의 냄비가 '낮은 도' 소리를 낼거야");
					hint_num += 1;
					s1lQ = false;
				}
				else {
					showMessage("음계상에서 1은 '도'겠지? \n 오른쪽 위의 냄비가 '낮은 도' 소리를 낼거야");
				}
			}
			else if (hint == 3) {
				if (s2lQ == true) {
					showMessage("귀찮더라도 일정표에 있는 날짜들을 달력에 표시해보면 \n 무언가가 보이지 않을까?");
					hint_num += 1;
					s2lQ = false;
				}
				else {
					showMessage("귀찮더라도 일정표에 있는 날짜들을 달력에 표시해보면 \n 무언가가 보이지 않을까?");
				}
			}
			else if (hint == 4) {
				if (s2rQ_chess == true) {
					showMessage("이건 eight queens problem인데 \n 2층 왼쪽 방의 그림에서 퀸3개를 추가시켜서 \n 퀸들이 서로 공격하지 못하는 상태를 유지해봐");
					hint_num += 1;
					s2rQ_chess = false;
				}
				else {
					showMessage("이건 eight queens problem인데 \n 2층 왼쪽 방의 그림에서 퀸3개를 추가시켜서 \n 퀸들이 서로 공격하지 못하는 상태를 유지해봐");
				}
			}
			else if (hint == 5) {
				if (s2rQ_chess_clear == false) {
					if (s2rQ_book == true) {
						showMessage("힌트는 이 방안에 있어. \n 노랑과 파랑의 중간은 과연 무슨 색일까?");
						hint_num += 1;
						s2rQ_book = false;
					}
					else {
						showMessage("힌트는 이 방안에 있어. \n 노랑과 파랑의 중간은 과연 무슨 색일까?");
					}
				}
				else if (s2rQ_book_clear == false) {
					if (s2rQ_chess == true) {
						showMessage("이건 eight queens problem인데 \n 2층 왼쪽 방의 그림에서 퀸3개를 추가시켜서 \n 퀸들이 서로 공격하지 못하는 상태를 유지해봐");
						hint_num += 1;
						s2rQ_chess = false;
					}
					else {
						showMessage("이건 eight queens problem인데 \n 2층 왼쪽 방의 그림에서 퀸3개를 추가시켜서 \n 퀸들이 서로 공격하지 못하는 상태를 유지해봐");
					}
				}
			}
			else if (hint == 6) {
				if (hint_num == 0) {
					showMessage("여태까지 한번도 질문을 안하고 여기까지 왔으니 이걸 줄게.");
					pickObject(key_s3r);
				}
				else {
					showMessage("이게 마지막 퀴즈야 . . . \n '위대한시간'과 '슬픔의시간'을 더해. 슬픔의 색이 뭔지는 알지?");
				}
			}
			else if (hint == 7) {
				showMessage("수고했어. . .  나도 이제 갈게");
				s1_right_light = true;
				s1_right_helper = false;
				hideObject(s1r_picture_changed);
				showObject(s1r_picture);
			}
		}
	}
	else if (object == s1r_picture) {
		if (s1_right_light == true) {
			if (s1_right_helper == true) {
				showMessage("나를 뚫어져라 쳐다보는 것 같다");
			}
			else {
				showMessage("이제는 평범한 그림이 된 것 같다.");
			}
		}
	}
	else if (object == s1r_mirror) {
		if (s1_right_light == true) {
			showMessage("continuity  특수한 펜으로 적은 것 같다");
		}
		else {
			showMessage("_ont_nu_t_ 일부가 잘 보이지 않는다. 특수한 펜으로 적은 것 같다");
		}
	}
	else if (object == s1r_drawer) {
		if (p_s1_right_drawer1 == true) {
			showKeypad("ciiy", s1r_drawer);
		}
		else if (s1r2 == 1) {
			showMessage("방 열쇠가 있던자리. 서랍 안엔 아무것도 없다.");
		}
		else {
			showMessage("방 열쇠를 얻었다");
			pickObject(key_s1l);
			s1r2 = 1;
		}
	}
	else if (object == s1r_drawer2) {
		if (p_s1_right_drawer2 == true) {
			showKeypad("1425", s1r_drawer2);
		}
		else if (s1r1 == 1) {
			showMessage("노란색 레코드판이 있던 자리. 서랍장 안에는 아무것도 없다.");
		}
		else {
			showMessage("노란색 레코드판을 얻었다");
			pickObject(record_yellow);
			s1r1 = 1;
			hint = 2;
		}
	}
	else if (object == s1r_paper1) {
		showMessage("첫째날 밤, 그는 우리를 외딴산장에 초대했다. \n 둘째날 밤, 그는 우리를 위해 파티를 열었다.");
	}
	else if (object == s1r_paper2) {
		showMessage("셋째날 밤, 그는 우리에게 선물을 주었다. \n 넷째날 밤, 우리의 보석이 사라졌다.");
	}
	else if (object == s1r_paper3) {
		showMessage("다섯째날 밤, 우리 중 한명이 죽었다. \n 여섯째날 밤, 그곳엔 아무도 없었다.");
	}
	else if (object == s1r_book) {
		showMessage("빨간색은 위대한색, 노란색은 오만함의색, 파란색은 우울함의 색");
	}
	else if (object == s1r_bone) {
		showMessage("슬픔은 오만과 우울의 사이에 있으니..");
	}
	else if (object == s1r_clock) {
		showMessage("'파란'시계바늘의 시계가 '10시 30분'을 나타내고 있다.");
	}
	//s1_left
	else if (object == s1l_door) {
		enterScene(mainhall);
	}
	else if (object == s1l_sinkdrawer) {
		if (p_s1_left_sink == true) {
			showMessage("주방의 소리를 듣고 1,2,3,4,5,8을 1,3,5,8의 순서로 눌러라");
		}
		else if (s1l1 == 1) {
			showMessage("건전지가 있던 자리. 안엔 아무것도 없다.");
		}
		else {
			showMessage("안에 건전지가 있다.");
			pickObject(battery_record);
			s1l1 = 1;
			hint = 3;
		}
	}
	else if (object == s1l_play1) {
		playSound(s1l_1, false);
		if (a == 0) {
			a += 1;
		}
		else if (a == 4) {

		}
		else {
			a = 0;
		}
	}
	else if (object == s1l_play2) {
		playSound(s1l_2);
		if (a == 4) {

		}
		else {
			a = 0;
		}
		return;
	}
	else if (object == s1l_play3) {
		playSound(s1l_3);
		if (a == 1) {
			a += 1;
		}
		else if (a == 4) {

		}
		else {
			a = 0;
		}
	}
	else if (object == s1l_play4) {
		playSound(s1l_4);
		if (a == 4) {

		}
		else {
			a = 0;
		}
	}
	else if (object == s1l_play5) {
		playSound(s1l_5);
		if (a == 2) {
			a += 1;
		}
		else if (a == 4) {

		}
		else {
			a = 0;
		}
	}
	else if (object == s1l_play8) {
		playSound(s1l_8);
		if (a == 3) {
			a += 1;
			//playSound(lock);
			showMessage("무언가 열리는 소리가 들렸다");
			p_s1_left_sink = false;
		}
		else if (a == 4) {
		}
		else {
			a = 0;
		}
	}
	//s2_left
	if (object == s2l_door) {
		enterScene(mainhall);
	}
	else if (object == s2l_board) {
		showMessage("의미없는 계획은 없다. 모든일에 의미를 부여하자. \n그 날짜까지에도.");
	}
	else if (object == s2l_picture1) {
		showImageViewer("eight_queens_hint.png");
		showMessage("8개의 퀸이 서로 공격할수 없도록 위치하게 할 수 있을까?");
	}
	else if (object == s2l_picture2) {
		showImageViewer("cal_23.png");
	}
	else if (object == s2l_picture3) {
		showImageViewer("cal_45.png");
	}
	else if (object == s2l_picture4) {
		showImageViewer("cal_67.png");
	}
	else if (object == s2l_picture5) {
		showImageViewer("cal_89.png");
	}
	else if (object == s2l_book) {
		showImageViewer("cal_plan_2.png"); 
	}
	else if (object == s2l_drawer) {
		if (p_s2_left_drawer1 == true) {
			showKeypad("5614", s2l_drawer);
		}
		else if (s2l1 == 1) {
			showMessage("방 열쇠가 있던 자리. 서랍장 안에는 아무것도 없다.");
		}
		else {
			showMessage("방 열쇠를 얻었다");
			pickObject(key_s2r);
			s2l1 = 1;
			hint = 4;
		}
	}
	else if (object == s2l_bookcase) {
		showMessage("체스에서 퀸(queen)은 가로, 세로, 대각선의 모든방향으로 \n 마음대로, 원하는 만큼 움직일 수 있다.");
	}
	else if (object == s2l_clock) {
		showMessage("'노란'시계바늘의 시계가 '08시 40분'을 나타내고 있다.");
	}
	//s2_right
	else if (object == s2r_chess) {
		enterScene(s2_right_chess);
		stopSound(stage2_BGM);
		playSound(chess_BGM, true);
	}
	else if (object == s2r_door) {
		enterScene(mainhall);
	}
	else if (object == s2r_book_RU) {
		showMessage("죄와 벌 \n 오만과 편견");
	}
	else if (object == s2r_book_RD) {
		showMessage("위대한 개츠비");
	}
	else if (object == s2r_book_LU) {
		showMessage("젊은 베르테르의 슬픔 \n 파리의 우울");
	}
	else if (object == s2r_book_LD) {
		showMessage("사랑의 학교");
	}
	else if (object == s2r_paper) {
		showMessage("노랑, 파랑, 초록, 빨강이 나타내는 책 제목의 글자수를 순서대로");
	}
	else if (object == s2r_drawer) {
		if (p_s2_right_drawer1 == true) {
			showKeypad("5596", s2r_drawer);
		}
		else if (s2r2 == 1) {
			showMessage("방 열쇠가 있던자리. 서랍 안엔 아무것도 없다.");
		}
		else {
			showMessage("방 열쇠를 얻었다");
			pickObject(key_s3l);
			s2r2 = 1;
			hint += 1;
			s2rQ_book_clear = false;
		}
	}
	else if (object == s2r_clock) {
		showMessage("'빨간'시계바늘의 시계가 '06시 30분'을 나타내고 있다.");
	}
	//s2_right_chess
	else if (object == chess_queen1) {

		if (queen1X == 505) {
			c -= 1;
		}
		else if (queen1X == 939) {
			c += 1;
			queen1X = 443, queen1Y = 357;
			if (c == 8) {
				if (s2r1 == 1) {
				}
				else {
					pickObject(record_green);
					showMessage("Clear! \n 초록색 레코드를 얻었다");
					s2r1 = 1;
					hint += 1;
					s2rQ_chess_clear = false;
				}
			}
		}
		queen1X += 62;
		queen1Y -= 7;
		locateObject(chess_queen1, s2_right_chess, queen1X, queen1Y);
	}
	else if (object == chess_queen2) {

		if (queen2X == 797) {
			c += 1;
			if (c == 8) {
				if (s2r1 == 1) {
				}
				else {
					pickObject(record_green);
					showMessage("Clear! \n 초록색 레코드를 얻었다");
					s2r1 = 1;
					hint += 1;
					s2rQ_chess_clear = false;
				}
			}
		}
		else if (queen2X == 859) {
			c -= 1;
		}
		else if (queen2X == 921) {
			queen2X = 425, queen2Y = 336;
		}
		queen2X += 62;
		queen2Y -= 7;
		locateObject(chess_queen2, s2_right_chess, queen2X, queen2Y);
	}
	else if (object == chess_queen3) {

		if (queen3X == 657) {
			c += 1;
			if (c == 8) {
				if (s2r1 == 1) {
				}
				else {
					pickObject(record_green);
					showMessage("Clear! \n 초록색 레코드를 얻었다");
					s2r1 = 1;
					hint += 1;
					s2rQ_chess_clear = false;
				}
			}
		}
		else if (queen3X == 719) {
			c -= 1;
		}
		else if (queen3X == 905) {
			queen3X = 409, queen3Y = 315;
		}
		queen3X += 62;
		queen3Y -= 7;
		locateObject(chess_queen3, s2_right_chess, queen3X, queen3Y);
	}
	else if (object == chess_queen4) {

		if (queen4X == 825) {
			c += 1;
			if (c == 8) {
				if (s2r1 == 1) {
				}
				else {
					pickObject(record_green);
					showMessage("Clear! \n 초록색 레코드를 얻었다");
					s2r1 = 1;
					hint += 1;
					s2rQ_chess_clear = false;
				}
			}
		}
		else if (queen4X == 887) {
			c -= 1;
			queen4X = 391, queen4Y = 290;
		}
		queen4X += 62;
		queen4Y -= 7;
		locateObject(chess_queen4, s2_right_chess, queen4X, queen4Y);
	}
	else if (object == chess_queen5) {

		if (queen5X == 426) {
			c += 1;
			if (c == 8) {
				if (s2r1 == 1) {
				}
				else {
					pickObject(record_green);
					showMessage("Clear! \n 초록색 레코드를 얻었다");
					s2r1 = 1;
					hint += 1;
					s2rQ_chess_clear = false;
				}
			}
		}
		else if (queen5X == 490) {
			c -= 1;
		}
		else if (queen5X == 874) {
			queen5X = 362, queen5Y = 265;
		}
		queen5X += 64;
		queen5Y -= 7;
		locateObject(chess_queen5, s2_right_chess, queen5X, queen5Y);
	}
	else if (object == chess_queen6) {

		if (queen6X == 532) {
				c += 1;
			if (c == 8) {
				if (s2r1 == 1) {
				}
				else {
					pickObject(record_green);
					showMessage("Clear! \n 초록색 레코드를 얻었다");
					s2r1 = 1;
					hint += 1;
					s2rQ_chess_clear = false;
				}
			}
		}
		else if (queen6X == 598) {
			c -= 1;
		}
		else if (queen6X == 862) {
			queen6X = 334, queen6Y = 240;
		}
		queen6X += 66;
		queen6Y -= 7;
		locateObject(chess_queen6, s2_right_chess, queen6X, queen6Y);
	}
	else if (object == chess_queen7) {

		if (queen7X == 650) {
			c += 1;
			if (c == 8) {
				if (s2r1 == 1) {
				}
				else {
					pickObject(record_green);
					showMessage("Clear! \n 초록색 레코드를 얻었다");
					s2r1 = 1;
					hint += 1;
					s2rQ_chess_clear = false;
				}
			}
		}
		else if (queen7X == 719) {
			c -= 1;
		}
		else if (queen7X == 857) {
			queen7X = 305, queen7Y = 216;
		}
		queen7X += 69;
		queen7Y -= 8;
		locateObject(chess_queen7, s2_right_chess, queen7X, queen7Y);
	}
	else if (object == chess_queen8) {

		if (queen8X == 418) {
			c += 1;
			if (c == 8) {
				if (s2r1 == 1) {
				}
				else {
					pickObject(record_green);
					showMessage("Clear! \n 초록색 레코드를 얻었다");
					s2r1 = 1;
					hint += 1;
					s2rQ_chess_clear = false;
				}
			}
		}
		else if (queen8X == 488) {
			c -= 1;
		}
		else if (queen8X == 838) {
			queen8X = 278, queen8Y = 192;
		}
		queen8X += 70;
		queen8Y -= 9;
		locateObject(chess_queen8, s2_right_chess, queen8X, queen8Y);
	}
	else if (object == s2r_chess_door) {
		enterScene(s2_right);
		stopSound(chess_BGM);
		playSound(stage2_BGM, true);
	}
	//s3_left
	else if (object == s3l_door) {
		enterScene(mainhall);
	}
	else if (object == s3l_book) {
		showMessage("누군가의 도움을 받아라");	
	}
	else if (object == s3l_room) {
		showMessage("적막감이 감도는 고요한 방이다 \n 이 방이 마지막인건가");
	}
	else if (object == s3l_handle) {
		if (p_s3_left_handle == true) {
			showKeypad("1605", s3l_handle);
		}
		else {
			if (hint_num == 1 || hint_num==2) {
				showMessage("'위대'의 문이 열렸다.");
				exit_door = 1;
				showObject(door_exit);
			}
			else if (hint_num ==3 || hint_num==4) {
				showMessage("'오만'의 문이 열렸다.");
				exit_door = 2;
				showObject(door_exit);
			}
			else if (hint_num==5) {
				showMessage("'슬픔'의 문이 열렸다.");
				exit_door = 3;
				showObject(door_exit);
			}
			else {
				showMessage("이스터에그: 제작자의 방이 열렸습니다");
				exit_door = 4;
				showObject(door_exit);
			}
			hint = 7;
		}
	}
	//stage3_right_hidden
	else if (object == s3r_door) {
		enterScene(mainhall);
	}
	else if (object == s3r_key) {
		pickObject(key_hidden);
		exit_door = 4;
		showMessage("다르게 생긴 열쇠를 얻었다.");
	}
	else if (object == s3r_book5) {
		showMessage("이 방은 마지막을 제외한 힌트의 도움을 \n하나도 받지 않았을 경우 들어올 수 있는 이스터 에그입니다. \n 플레이 해주셔서 정말 감사합니다.");
	}
	else if (object == s3r_book1) {
		showMessage("이미지");
		showImageViewer("s3_right_image1.png");
	}
	else if (object == s3r_book2) {
		showMessage("음원");
		showImageViewer("s3_right_image2.png");
	}
	else if (object == s3r_book3) {
		showMessage("퀴즈");
		showImageViewer("s3_right_image3.png");
	}
	else if (object == s3r_book4) {
		showMessage("후기");
		showImageViewer("s3_right_image4.png");
	}

	//ending 1
	else if (object == ending_1) {
		char end1[20];
		sprintf_s(end1, "힌트 %d회 사용", hint_num);
		showMessage(end1);
		showObject(ending1_exit);
	}
	else if (object == ending1_exit) {
		endGame();
	}
	else if (object == ending_2) {
		char end2[20];
		sprintf_s(end2, "힌트 %d회 사용", hint_num);
		showMessage(end2);
		showObject(ending2_exit);
		}
	else if (object == ending2_exit) {
		endGame();
	}
	else if (object == ending_3) {
		char end3[20];
		sprintf_s(end3, "힌트 %d회 사용", hint_num);
		showMessage(end3);
		showObject(ending3_exit);
	}
	else if (object == ending3_exit) {
		endGame();
	}
	else if (object == ending_4) {
		showMessage("플레이 해주셔서 감사합니다!!! \n 힌트를 한번도 안보셨다니, 대단하네요!");
		showObject(ending4_exit);
	}
	else if (object == ending4_exit) {
		endGame();
	}
}


void objectCallback(ObjectID object, EventID event)
{
	if (object == s1r_drawer2) {
		if (event == EventID::EVENT_KEYPAD) {
			p_s1_right_drawer2 = false;
			playSound(lock);
			showMessage("잠금이 해제되었다!");
		}
	}
	else if (object == s1r_drawer) {
		if (event == EventID::EVENT_KEYPAD) {
			p_s1_right_drawer1 = false;
			playSound(lock);
			showMessage("잠금이 해제되었다!");
		}
	}
	else if (object == s2l_drawer) {
		if (event == EventID::EVENT_KEYPAD) {
			p_s2_left_drawer1 = false;
			playSound(lock);
			showMessage("잠금이 해제되었다!");
		}
	}
	else if (object == s2r_drawer) {
		if (event == EventID::EVENT_KEYPAD) {
			p_s2_right_drawer1 = false;
			playSound(lock);
			showMessage("잠금이 해제되었다!");
		}
	}
	else if (object == s3l_handle) {
		if (event == EventID::EVENT_KEYPAD) {
			p_s3_left_handle = false;
			playSound(lock);
			showMessage("스위치가 작동되었다!");
		}
	}
}

int main() {
	setMouseCallback(mouseCallback);
	setObjectCallback(objectCallback);

	game_start();
	object_create();	
	sound_create();
	playSound(start_BGM,true);
	startGame(start);
}