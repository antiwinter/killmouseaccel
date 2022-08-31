### Forked from [docwhat/killmouseaccel](https://github.com/docwhat/killmouseaccel), which was originally copied from http://forums3.armagetronad.net/viewtopic.php?p=196564#p196564

----
## Modifications

* Removed the xcode project dependency, just `make` and go
* Removed the **trackpad** support, acceleration on **trackpad** feels just fine.

```
make
./a.out
```

or if you'd like to control the acceleration value, feel free to append a number after `./a.out`:
```
./a.out 10000
```

## Note
When I got this script working, I've already get used to the acceleration feeling of the mouse, so I decided to not kill it.
