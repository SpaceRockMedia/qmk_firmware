# Spacerock userspace

This my persnal userspace for my qmk keymaps and used features. The root directory has a
few files to help keep things orgaized.

* [spacerock.c](spacerock.c) : The main entrypoint
* [spacerock.h](spacerock.h) : The loads the keycodes and features header files
* [rules.mk](rules.mk) : the main rules fils. All rules associated with features
  are located in the features rules.mk file.
* [config.h](config.h) : starts the loading of the features config files.
* [combos.def](combos.def) : placeholder file required by the combos.def setup.
* `util/` : folder that contains utility code that doesnt belong anywhere else.
* [keycodes/](keycodes/Readme.md) : registers all the keycodes used through my keymaps
* [features](features/Readme.md) : where most of the magic happens. I tried my best to take
  any configuration items and place them in this folder orgaized be the named feature.

# Goals
My goals are to make this as modular as it can, within reason. As i take ideas from many
others keeping them orgaized helps a lot with code clarity.

I explicitly did not use the keymap magic others do to transform keymaps into other sizes
as i feel that makes it much harder for new users to understand what is going on. So I
maually defined my keymaps on the following boards:

* [splitkb kyria](../../keyboards/splitkb/kyria/keymaps/spacerock)
* [reviung41](../../keyboards/reviung/reviung41/keymaps/spacerock)
* [hillside52](../../keyboards/hillside/52/keymaps/spacerock)

# Inspiration

I borrowed a lot of ideas from others. It started with
[Drashna's userspace](https://github.com/qmk/qmk_firmware/tree/master/users/drashna)
then many others like Urob, Callum, [Ben Vallek](https://www.youtube.com/watch?v=8wZ8FRwOzhU)
and may others i will add here as i remember them and clean up.
