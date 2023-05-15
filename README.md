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
```

Generate sprite data
//  -mRtpf
```bash
rm -rf sprites/generated
mkdir sprites/generated
cd sprites/generated
grit ../animals/pngs/*.png ../ui/pngs/*.png -pS -gB8 -gTFFAAFF -ftc -Osprites
```

Generate background data

```bash
cd sprites/generated
grit ../extras/bg.png -gTFFAAFF -gB4 -mRtpf -ftc
```

Generate animals.h
```bash
rm sprites/extras.h
echo "#ifndef SUPERADVANCEPETS_ANIMALS_H" > sprites/extras.h
echo "#define SUPERADVANCEPETS_ANIMALS_H" >> sprites/extras.h
for i in sprites/extras/extras/*.bmp; do
    [ -f "$i" ] || break
    filename=$(basename -- $i)
    filename="${filename%.*}"
    echo $filename
    echo "#include \"${filename}.h\"" >> sprites/extras.h
done
echo "#endif //SUPERADVANCEPETS_ANIMALS_H" >> sprites/extras.h
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


Cut Up UI Sheet
```bash
cd sprites/ui
rm pngs/*
convert ui.png -crop 16x16@ +repage +adjoin ui_8x8_%d.png
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
mv ui_8x8_21.png pngs/num10.png

mv ui_8x8_6.png pngs/uiTrophy8x8.png
mv ui_8x8_7.png pngs/uiCoin8x8.png
mv ui_8x8_22.png pngs/uiHeart8x8.png
mv ui_8x8_23.png pngs/uiTurns8x8.png

rm ui_8x8_*.png
convert ui.png -crop 8x8@ +repage +adjoin ui_16x16_%d.png

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

rm ui_16x16_*.png
convert ui.png -crop 4x8@ +repage +adjoin ui_32x16_%d.png
mv ui_32x16_2.png pngs/uiLeftBumperRoll.png
mv ui_32x16_3.png pngs/uiRightBumperFight.png

rm ui_32x16_*.png
convert ui.png -crop 2x4@ +repage +adjoin ui_64x32_%d.png

mv ui_64x32_4.png pngs/uiModal.png
rm ui_64x32_*.png
```