i#ifndef _VIEW_H
#define _VIEW_H
class CView
{
	private:
		CView();
	
	public:	static CView * GetView();
		~CView();
		void DoMainLoop();
		static const int RED=1, GREEN=2, YELLOW=3, BLUE=4, MAGENTA=5, CYAN=6, WHITE=7;
		void DrawText(int y, int x, const char * str, int color);
		void DrawTextArea(int y, int x, const char * str, int color, int width);
	
		void Rectangle(int x, int y, int width, int height, int color);
		void EraseRect(int x, int y, int width, int height);
	
		void DrawBox(int x, int y, const char * name, int color);
		void DrawCheckBox(int x, int y, const char * name, bool checked, int color);
		void DrawRadio(int x, int y, const char * name, bool checked, int color);
};
#endif