#ifndef CONFIG_HPP
#define CONFIG_HPP

//What you get to play with!
#define WINDOW_WIDTH 240
#define WINDOW_HEIGHT 320
#define WINDOW_SIZE_MULTIPLIER 2.0
template<typename T> T getX(T in) { return in * WINDOW_SIZE_MULTIPLIER; }
template<typename T> T getY(T in) { return in * WINDOW_SIZE_MULTIPLIER; }


//Some math
#define WINDOW_W WINDOW_WIDTH * WINDOW_SIZE_MULTIPLIER
#define WINDOW_H WINDOW_HEIGHT * WINDOW_SIZE_MULTIPLIER
#endif // CONFIG_HPP
