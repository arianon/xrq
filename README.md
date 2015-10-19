# xrq
**X** **R**esource **Q**uery,
A program for querying the X Resources Database from the command line.

## Installing
```sh
$ git clone https://github.com/arianon/xres
$ cd xres
$ make
$ sudo make install
```

## Usage
On my computer, the following command:
```sh
$ xrq URxvt.foreground URxvt.background URxvt.font
```
yields the following values.
```
#b7bdcc
#14181f
-*-tewi-medium-*-*-*-11-*-*-*-*-*-iso10646-*
```

For querying all 16 colors, one could take advantage of shell expansion.
```sh
$ xrq URxvt.color{0..15}
```
yields
```
#2b303b
#994e55
#849971
#c5aa75
#707e8c
#8f7189
#778f8e
#a6aab2
#4d576b
#bf616a
#a3be8c
#ebcb8b
#8fa1b3
#b48ead
#96b5b4
#b9bbbe
```

If in your `~/.Xresources` or `~/.Xdefaults`, you use glob patterns - such as `*color4: #aabbcc` - you could simply skip the class's name that precedes the resource name. thus the above commands could become this:

```sh
$ xrq color{0..15}
```
