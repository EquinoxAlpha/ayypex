This project is very hard to maintain, it crashes all the time and it's a pain to restart the game every time you need to reload the cheat to check if new features work or not. For this reason, I'm making an external version which should be much easier to develop AND much safer (harder to detect with it using mouse input and being external): https://github.com/EquinoxAlpha/ext-ayypex, and this project is for the foreseeable future semi-abandoned. If you want to make your own internal or any other vulkan layer related project, you can simply copy+paste the include directories and everything in the "vk_hook" directory. The vulkan layer should be pretty simple to use, just rip out all the cheat code (basically everything in "src/core/"). All it does is call some on-frame functions, removing the need to know how to use Vulkan.

Here's the old description:

# ayypex

A cheat for Apex Legends, for use with Proton on Linux.
It is internal, using a Vulkan layer to render directly on the game's window, like how MangoHud does it.

## Features

Currently, ayypex has:

* Wallhack (box ESP)
* Glow (enemies change color if they are visible)
* Recoil control
* Aim Assist with prediction (sway compensation is broken though)

The cheat will try to read settings from ~/ayypex_settings.json, but if a setting is not found, a default is used instead. It also detects when the settings file is changed. A sample settings file is included.

## Installing

To install the internal version,

* Move the ayypex.json file to /usr/share/vulkan/implicit_layer.d
* Add AYYPEX=1 %command% to launch options in Steam
* Compile with make
* Install with make install
* Run the game.

## Porting to external
I haven't done this! But it should work...

Files that need to be changed:
* src/core/mem.h (Replace mem::read and mem::write)

Next, you'll need a way to call:
* core::tick(float delta_time) (delta_time should be in seconds)
* core::draw()                 (You'll need to write some kind of overlay with ImGui)
* core::init()                 (Simply call this when your cheat starts.)

## Planned features
(In order of importance)

* ~~Settings (that can be reloaded at runtime)~~
* Triggerbot
* Spectator count
* Item glow
* Optimize entitylist reading (not really needed since we're internal, but it's nice to have)
* Read offsets from INI file
* Use mouse movement instead of writing to viewangles

## Bugs

* The game crashes when leaving a match. (Probably due to aimassist? It started doing that after I re-enabled it...)
* There is a small chance you will crash when entering a match. (I have no idea why)
* Settings reload function called twice when a change is detected

## Detection status

I will update this section if I get banned. Most likely feature that could get you banned is aim assist or recoil control. However, I've been using an earlier development version of this with only wallhack for about a month and I'm yet to be banned.

## Credits

* MangoHud for their Vulkan layer code, which was modified and shortened for this project.
* The UnKnoWnCheaTs forum.
