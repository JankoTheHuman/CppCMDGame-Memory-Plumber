Top down game using PDCurses and SFLM for audio I've created a game in Command Window. It is a dungeon crawler with currently one level, and a boos.

Story:
Your world is under attack by an evil virus that occupies and leaks operational memory all over the world!
You are a plumber, and your task is to stop the leak!
If you don't stop the leak in time, the world around you will cease to exist!

As said by the story, game leaks memory (kinda). It allocates memory to an array of random size at random intervals, when picked up memory fragments some memory is released, and all memory is released 
if game is exited safely or boss it beat.
If level takes too much time to beat, too much memory will be leaked(allocated) and game crashes(purposfully).

You can find images of the game in the GameVisualPreview.

You are plumber, stop the leak!

