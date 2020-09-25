#pragma once

/*
 ^ Overview of class window
 ^ has 4 coords and one title thats it
 ^ More features in adding
*/
class Window {
public:
	// & New feature implementation
	static int instances;
	static char name[20];
	int lastCursorPosition[2];
	static int buffer_data[3][2];
	int m_x1, m_x2, m_y1, m_y2;
	char *m_title;
	bool isDestroyed = false;

	Window() : m_x1(0), m_x2(80), m_y1(0), m_y2(25), m_title((char *)"HALIDE OS v.0.1") {}

	Window(int x1, int x2, int y1, int y2, char *title) : m_x1(x1), m_x2(x2), m_y1(y1), m_y2(y2), m_title(title) { instances++; }

	void storeBuffer(int y_upper, int y_lower) {
		buffer_data[instances][0] = y_upper;
		buffer_data[instances][1] = y_lower;
	}

	void DestroyWindow(Window *window) {
		int temp, temp1;
		temp = buffer_data[instances][0];
		temp1 = buffer_data[instances][1];
		buffer_data[instances][0] = -1;
		buffer_data[instances][1] = -1;
		m_y1 = -1;
		m_y2 = -1;
		isDestroyed = true;
		instances--;
		window->m_y1 += 1;
		window->m_y2 = 25;
		// m_y1 = buffer_data[instances][0];
		// m_y2 = buffer_data[instances][1];
	}
}__attribute__((packed));
