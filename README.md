# Super Advance Pets

## Building CLI (Standalone Engine)

```bash
make SuperAutoPetsCLI
```

## Building GBA (Full Game)
```bash
make -f Makefile.gba
```

```bash
make -f Makefile.gba && vba --video-4x sap.gba
```

## Building Sprites

Convert regular bmps to pink background
```bash
mkdir sprites/ui/pngs
cd sprites/ui/pngs
for i in ../pngs/*.png; do
    [ -f "$i" ] || break
    echo $i
    filename="${i%.*}"
    echo $filename
    convert $i -compress none -background "#FFaaFF" -flatten "../bmps/${filename}.png"
done
cd ../../..
```

Generate sprite data
//  -mRtpf
```bash
rm -rf sprites/generated
mkdir sprites/generated
cd sprites/generated
grit ../animals/pngs/*.png ../ui/pngs/*.png -pS -gB8 -gTFFAAFF -ftc -Osprites
cd ../..
```

Generate background data

```bash
cd sprites/generated
grit ../extras/bg.png -gTFFAAFF -gB8 -mRtpf -mLs -ftc
grit ../extras/logo.png -gTFFAAFF -gB8 -mLs -ftc
cd ../..
```

Generate animals.h
```bash
rm sprites/animals.h
echo "#ifndef SUPERADVANCEPETS_ANIMALS_H" > sprites/generated/animals.h
echo "#define SUPERADVANCEPETS_ANIMALS_H" >> sprites/generated/animals.h
for i in sprites/animals/pngs/*.png; do
    [ -f "$i" ] || break
    filename=$(basename -- $i)
    filename="${filename%.*}"
    echo $filename
    echo "#include \"${filename}.h\"" >> sprites/generated/animals.h
done
echo "#endif //SUPERADVANCEPETS_ANIMALS_H" >> sprites/generated/animals.h
```

Generate ui.h
```bash
rm sprites/generated/ui.h
echo "#ifndef SUPERADVANCEPETS_UI_H" > sprites/generated/ui.h
echo "#define SUPERADVANCEPETS_UI_H" >> sprites/generated/ui.h
for i in sprites/ui/pngs/*.png; do
    [ -f "$i" ] || break
    filename=$(basename -- $i)
    filename="${filename%.*}"
    echo $filename
    echo "#include \"${filename}.h\"" >> sprites/generated/ui.h
done
echo "#endif //SUPERADVANCEPETS_UI_H" >> sprites/generated/ui.h
```


Make Graphics
```bash
cd sprites/ui
rm pngs/*
convert ui.png -crop 16x20@ +repage +adjoin ui_8x8_%d.png
mv ui_8x8_0.png pngs/num0.png
mv ui_8x8_1.png pngs/num1.png
mv ui_8x8_2.png pngs/num2.png
mv ui_8x8_3.png pngs/num3.png
mv ui_8x8_4.png pngs/num4.png
mv ui_8x8_16.png pngs/num5.png
mv ui_8x8_17.png pngs/num6.png
mv ui_8x8_18.png pngs/num7.png
mv ui_8x8_19.png pngs/num8.png
mv ui_8x8_20.png pngs/num9.png

mv ui_8x8_5.png pngs/uiThrowableStatAttack.png
mv ui_8x8_21.png pngs/uiThrowableDamage.png

mv ui_8x8_6.png pngs/uiTrophy8x8.png
mv ui_8x8_7.png pngs/uiCoin8x8.png
mv ui_8x8_22.png pngs/uiHeart8x8.png
mv ui_8x8_138.png pngs/uiChili8x8.png
mv ui_8x8_139.png pngs/uiMelon8x8.png
mv ui_8x8_140.png pngs/uiMeatBone8x8.png
mv ui_8x8_141.png pngs/uiHoney8x8.png
mv ui_8x8_142.png pngs/uiCoconut8x8.png
mv ui_8x8_154.png pngs/uiSteak8x8.png
mv ui_8x8_155.png pngs/uiMushroom8x8.png
mv ui_8x8_156.png pngs/uiGarlic8x8.png
mv ui_8x8_157.png pngs/uiPeanut8x8.png

mv ui_8x8_23.png pngs/uiTurns8x8.png

rm ui_8x8_*.png
convert ui.png -crop 8x10@ +repage +adjoin ui_16x16_%d.png

mv ui_16x16_8.png pngs/uiTrophy16x16.png
mv ui_16x16_9.png pngs/uiTrophyEmpty16x16.png
mv ui_16x16_10.png pngs/uiHeart16x16.png
mv ui_16x16_11.png pngs/uiHeartEmpty16x16.png
mv ui_16x16_12.png pngs/uiIceBlock16x16.png

mv ui_16x16_13.png pngs/uiBannerLvl1.png
mv ui_16x16_14.png pngs/uiBannerLvl2.png
mv ui_16x16_15.png pngs/uiBannerLvl3.png

mv ui_16x16_16.png pngs/uiBannerExpZero.png
mv ui_16x16_17.png pngs/uiBannerExpOne.png
mv ui_16x16_18.png pngs/uiBannerExpTwo.png
mv ui_16x16_19.png pngs/uiBannerExpThree.png

mv ui_16x16_20.png pngs/uiButtonA.png
mv ui_16x16_21.png pngs/uiButtonB.png
mv ui_16x16_22.png pngs/uiTagOK.png
mv ui_16x16_23.png pngs/uiTagJK.png

mv ui_16x16_24.png pngs/uiDice1.png
mv ui_16x16_25.png pngs/uiDice2.png
mv ui_16x16_26.png pngs/uiDice3.png
mv ui_16x16_27.png pngs/uiDice4.png
mv ui_16x16_28.png pngs/uiDice5.png
mv ui_16x16_29.png pngs/uiDice6.png

mv ui_16x16_30.png pngs/uiCursorOpen.png
mv ui_16x16_31.png pngs/uiCursorClose.png
mv ui_16x16_36.png pngs/uiBandaid.png

mv ui_16x16_46.png pngs/uiButtonAOutline.png
mv ui_16x16_47.png pngs/uiButtonBOutline.png

mv ui_16x16_68.png pngs/poofFrame0.png
mv ui_16x16_69.png pngs/poofFrame1.png
mv ui_16x16_70.png pngs/poofFrame2.png

mv ui_16x16_62.png pngs/uiBannerShort.png

rm ui_16x16_*.png
convert ui.png -crop 4x10@ +repage +adjoin ui_32x16_%d.png
mv ui_32x16_2.png pngs/uiLeftBumperRoll.png
mv ui_32x16_3.png pngs/uiRightBumperFight.png

mv ui_32x16_22.png pngs/uiLabelFreeze.png
mv ui_32x16_24.png pngs/uiLabelCancel.png
mv ui_32x16_25.png pngs/uiLabelSell.png
mv ui_32x16_26.png pngs/uiLabelBuy.png
mv ui_32x16_27.png pngs/uiLabelMove.png
mv ui_32x16_28.png pngs/uiLabelStack.png
mv ui_32x16_29.png pngs/uiLabelPlace.png
mv ui_32x16_30.png pngs/uiLabelSwap.png
rm ui_32x16_*.png

convert ui.png -crop 4x5@ +repage +adjoin ui_32x32_%d.png

mv ui_32x32_8.png pngs/uiFrown32x32.png
mv ui_32x32_9.png pngs/uiSmile32x32.png
mv ui_32x32_16.png pngs/uiMeh32x32.png
mv ui_32x32_17.png pngs/uiTrophy32x32.png
rm ui_32x32_*.png
cd ../..

rm -rf sprites/generated
mkdir sprites/generated
cd sprites/generated
grit ../animals/pngs/*.png ../ui/pngs/*.png -pS -gB8 -gTFFAAFF -ftc -Osprites
cd ../..

cd sprites/generated
grit ../extras/bg.png -gTFFAAFF -gB8 -mRtpf -mLs -ftc
grit ../extras/logo.png -gTFFAAFF -gB8 -mLs -ftc
cd ../..

rm sprites/generated/ui.h
echo "#ifndef SUPERADVANCEPETS_UI_H" > sprites/generated/ui.h
echo "#define SUPERADVANCEPETS_UI_H" >> sprites/generated/ui.h
for i in sprites/ui/pngs/*.png; do
    [ -f "$i" ] || break
    filename=$(basename -- $i)
    filename="${filename%.*}"
    echo $filename
    echo "#include \"${filename}.h\"" >> sprites/generated/ui.h
done
echo "#endif //SUPERADVANCEPETS_UI_H" >> sprites/generated/ui.h

rm sprites/animals.h

echo "#ifndef SUPERADVANCEPETS_ANIMALS_H" > sprites/generated/animals.h
echo "#define SUPERADVANCEPETS_ANIMALS_H" >> sprites/generated/animals.h
for i in sprites/animals/pngs/*.png; do
    [ -f "$i" ] || break
    filename=$(basename -- $i)
    filename="${filename%.*}"
    echo $filename
    echo "#include \"${filename}.h\"" >> sprites/generated/animals.h
done
echo "#endif //SUPERADVANCEPETS_ANIMALS_H" >> sprites/generated/animals.h

```