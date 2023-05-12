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
mkdir sprites/bmps/animals
cd sprites/bmps/animals
for i in ../animals.transparent/*.bmp; do
    [ -f "$i" ] || break
    echo $i
    filename="${i%.*}"
    echo $filename
    convert $i -compress none -background "#FFaaFF" -flatten "${filename}.png"
done
```

Generate sprite data

```bash
cd sprites
grit bmps/animals/*.png -pS -gB8 -gTFFAAFF -mRtpf -ftc -Osprites
```

Generate animals.h
```bash
rm sprites/animals.h
echo "#ifndef SUPERADVANCEPETS_ANIMALS_H" > sprites/animals.h
echo "#define SUPERADVANCEPETS_ANIMALS_H" >> sprites/animals.h
for i in sprites/bmps/animals/*.bmp; do
    [ -f "$i" ] || break
    filename=$(basename -- $i)
    filename="${filename%.*}"
    echo $filename
    echo "#include \"${filename}.h\"" >> sprites/animals.h
done
echo "#endif //SUPERADVANCEPETS_ANIMALS_H" >> sprites/animals.h
```