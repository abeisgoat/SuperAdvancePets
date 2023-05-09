# Super Advance Pets

## Building Sprites

```bash
cd sprites
for i in bmps/animals/*.bmp; do
    [ -f "$i" ] || break
    wine ~/Desktop/grit/grit.exe $i -gB4 -gTFFAAFF -mRtpf -ftc
done
```

```bash
for i in sprites/bmps/animals/*.bmp; do
    [ -f "$i" ] || break
    echo $i
    convert $i -define bmp:format=bmp2 -compress none -background "#FFaaFF" -flatten $i
done
```