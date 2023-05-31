//
// Created by abe on 5/16/23.
//

#ifndef SUPERADVANCEPETSCLI_MEM_MANAGER_ENUMS_H
#define SUPERADVANCEPETSCLI_MEM_MANAGER_ENUMS_H
enum UIIcon {
    UIIcon_Coin,
    UIIcon_Hearts,
    UIIcon_Turns,
    UIIcon_Trophy,
    UIIcon_Chili,
    UIIcon_Melon,
    UIIcon_Meatbone,
    UIIcon_Honey,
    UIIcon_Steak,
    UIIcon_Mushroom,
    UIIcon_Garlic,
    UIIcon_Peanuts
};

enum UIElements32x16 {
    UIElement_LeftBumperRoll=1,
    UIElement_RightBumperFight=0,
};

enum UILabels {
    UILabel_Cancel,
    UILabel_Buy,
    UILabel_Freeze,
    UILabel_Sell,
    UILabel_Move,
    UILabel_Stack,
    UILabel_Place,
    UILabel_Swap,
    UILabel_None,
};

enum UIElements32x32 {
    UIElement32x32_Smile,
    UIElement32x32_Frown,
    UIElement32x32_Meh,
    UIElement32x32_Trophy
};

enum UIElements16x16 {
    UIElement_Btn_A_Outline,
    UIElement_Btn_B_Outline,
    UIElement_IceBlock,
    UIElement_Bandaid,
    UIElement_Heart,
    UIElement_HeartEmpty,
    UIElement_Trophy,
    UIElement_TrophyEmpty
};

enum UIThrowable {
    UIThrowable_Stats,
    UIThrowable_StatAttack,
    UIThrowable_StatHealth,
    UIThrowable_Damage
};
#endif //SUPERADVANCEPETSCLI_MEM_MANAGER_ENUMS_H
