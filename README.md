# Spacehack
[![Build Status](https://travis-ci.org/thomasscottterry121/roguelike.svg?branch=master)](https://travis-ci.org/thomasscottterry121/roguelike)



Prepare your programming environment. Choose your language and platform, choose appropriate compilers/interpreters, editor, version control, automated build, and other utilities. Set them up so that you're comfortable with them.
Decide on which libraries you're going to use -- it can change later, but it's usually a painful change. Don't think too much about portability -- it can be fixed later. Think about what you need and what you're comfortable with.
Decide on the language you want to write comments and object names in your code, as well as the language you want to be used in your game. It's strongly recommended to use English in your source code -- you can get more help this way from others.
Don't worry about i18n yet; translation is usually a very late step in the development process.
Write a simple 'Hello world!' program and test whether it works. Test your libraries, etc. -- you don't want any surprises.
Start coding.

Step 3 - It's a boy!

Start with screen output and keyboard input. Decide preemptively on your screen layout (easy, you can change it later) and make the routines that display map characters, status lines and messages.
Make the routine to read key-presses (no config files, no keys redefinition).
Make a '@ walking around the empty screen' demo. Play with it a little, clean things up, play some more, imagining the game is finished and you're playing it.
Make the message handling routines -- especially for the debugging messages -- they come in handy.


Step 4 - The map

Decide on your map structure. Don't over-generalize -- you can add things later. Make your (empty) map displayed on the screen. Scrolled if you need it. Add some elements to your map to see if they are displayed correctly (just hard-code them, you don't need a level generator yet).
Make your '@' appear on the map -- not as it's element at first, just as a cursor. Test the scrolling, maybe make a 'look' command.
Now turn '@' into creature. You still don't have time implemented, so the keyboard-reading routines will just move it around the map. Include the checks for walls in the movement code. Maybe add doors and open/close commands.


Step 5 - Saving/Loading

(First: Note that you can initially do away with save and load entirely - a feature not present in many early implementations - and generate your dungeons instead of hard-coding them, which is arguably a more roguelike approach!)
Read the map from a file instead of hard-coding it. You can play with it and test different configurations if you make it human-readable from the start.
Add the 'save' command and the procedures to save your game -- the map at first, then, gradually, all of other game elements. From now on, when you implement something that needs saving, also implement saving it as soon as possible.
Here's a handy article about save files and how to implement them; it's worthwhile to read when planning ahead what form you'll save things in.
Once you work with files, you can make your preferences and keybindings config files. Again, if you make them human-readable, you'll save yourself a lot of trouble.
Now, when you're not sure how any element of the game works, you can save the game to a file and just check it.


Step 6 - It's alive! Alive!

Implement other creatures (monsters) and time. Add a single monster to begin with. Give him some simple AI (like, say, stay still, or maybe move randomly).
Start with my turn-your turn, then implement the time system you want (or, usually, a simplification of it and gradually make it more complicated later).
(Note: If you use a library, it can be easy to implement The Incredible Power of Dijkstra Maps. See also Dijkstra Maps Visualized.)
Remember to test everything as you go.


Step 7 - Interaction

Add stats for your creatures. A simplification of the ones you envisioned, probably. It's best to add stats as they are needed, not because they 'look cool', but you might not be able to resist ;).
Make the creatures notice each other -- bump, attack, etc. Gradually improve their AIs, so that they can chase the player.
Implement and test the combat system -- without equipment for now, just hardcode the values. Do lots of testing.


Step 8 - Data files

Move the creature, map features, etc. definitions to data files. Forget about scripting for now If something cannot be moved -- just leave it for now.
(Note: This is an irrelevant step for interpreted languages. You may instead take the opportunity to organize your code in such a way as to make adding new denizens or map features an easy process.)


Step 9 - Items

Add items. For start, just objects you can pick up -- no properties. Gradually give them properties, kinds, stats, etc., implement inventory, picking up and dropping, equipping and using (no effects yet), also stacking, containers (if you want them), etc.
This step usually requires lots of testing to balance.


Step 10 - Magic

Add item effects, special monster attacks, spells. Add items and monsters to test them. You don't need all the possible effects right away, just the ones that are needed for the next step.


Step 11 - Simple game

Try to make a simple, hard-coded game. Play it and give it to your friends. Test the mechanics you've implemented so far. See if the game is fun.
Change everything you need to change. Don't forget to test a lot. Always ask someone to test the game's 'fun factor', or test it yourself after a while; it's hard to notice some things right away.
This step should take a pretty long time, until you've got a playable, fun mini-game.


Step 12 - Levels

Write your level generators. Implement moving between the levels, a wilderness and/or town if you want them, saving the levels on level change if you want them to be persistent (so that they don't take up memory).
Spread your monsters and items on different depths. Add more monsters and items, with their effects, as needed.


Step 13 - Experience

Start developing your experience system and skill system. Tune the monsters' and items' stats. Make character generation screen, classes, races, and whatever else you need.
Playtest your game frequently.


Step 14 - Citizens

Add NPCs, shopkeepers, and simple quests if you need them. Keep adding features and tuning the stats.


Step 15 - Free at last

Start adding and testing all the 'unique' features you thought were so cool months (years?) ago, when you started the whole thing. Revise your opinions of them and see if they fit the game.
Write your pet random plot generator, factions system, infinite wilderness generator, neural network AI, or other unique feature, since you can now test it in a working game.
