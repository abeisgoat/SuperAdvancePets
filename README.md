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

```bash
rm -rf sprites/generated
mkdir sprites/generated
cd sprites/generated
grit ../animals/pngs/*.png ../ui/pngs/*.png -pS -gB8 -gTFFAAFF -mRtpf -ftc -Osprites
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

Cut Up UI Sheet
```bash
cd sprites/ui
rm pngs/*
convert ui.png -crop 8x8@ +repage +adjoin ui_%d.png
mv ui_0.png pngs/uiBannerTopLvl1.png
mv ui_1.png pngs/uiBannerTopLvl2.png
mv ui_2.png pngs/uiBannerTopLvl3.png
mv ui_3.png pngs/num0.png
mv ui_4.png pngs/num1.png
mv ui_5.png pngs/num2.png
mv ui_6.png pngs/num3.png
mv ui_7.png pngs/num4.png
mv ui_8.png pngs/uiBannerBottomEmpty.png
mv ui_9.png pngs/uiBannerBottomOneThirds.png
mv ui_10.png pngs/uiBannerBottomTwoThirds.png
mv ui_11.png pngs/num5.png
mv ui_12.png pngs/num6.png
mv ui_13.png pngs/num7.png
mv ui_14.png pngs/num8.png
mv ui_15.png pngs/num9.png
rm ui_*.png
```