#include "../menu.h"
#include <iostream>
#include <windows.h>
#include <locale.h>
#include "../Tree.h"
#include <limits>
#include <stdlib.h>


int main()
{ 
	FontsSettings(0, 16);
	console = GetConsoleWindow();
	SetWindowPos(console, NULL, PosConsole.x, PosConsole.y, sizeConsole.x, sizeConsole.y, NULL);
	SetWindowLong(console, GWL_STYLE, WS_BORDER);
	ShowWindow(console, SW_SHOW);
	ExConsole();
	loading();		
				
	pRoot = NULL;

	while (1) {
		field A[8] = { "Create RANDOM TREE", "Search a vertex by inf", "Add new vertex to Tree (recursion)", "Add new vertex to Tree (non recursion)", "line-by-line tree output based on Reverse_Inorder_traversal", "inline output based on Preorder_traversal", "delete the vertex", "Exit" };
		bool back = 0;
		int choice = menu(A, 8);

		if (choice == 0) {
			int count = stoi(Get_el_console("Enter a count of vertex:"));
			Create_Tree(count);
			while (!back) {
				field SEARCH[2] = { "The Tree was created successfully!", "Back" };
				if (menu(SEARCH, 2) == 1) back = 1;
			}
		}

		if (choice == 1) {
			int inf = stoi(Get_el_console("Enter a inf of vertex:"));
			Search(inf);
			while (!back) {
				field SEARCH[2] = { "The vertex with inf - " + std::to_string(inf) + " not found!", "Back" };
				if (stop) {
					SEARCH[0].name = "The vertex with inf - " + std::to_string(inf) + " has a " + std::to_string(pFind->count) + "reps";
				}
				if (menu(SEARCH, 2) == 1) back = 1;
			}
		}

		else if (choice == 2) {
			int inf = stoi(Get_el_console("Enter a inf of vertex:"));
			Add_recursion(inf);
			while (!back) {
				field SEARCH[2] = { "The vertex was added successfully", "Back" };
				if (menu(SEARCH, 2) == 1) back = 1;
			}
		}

		else if (choice == 3) {
			int inf = stoi(Get_el_console("Enter a inf of vertex:"));
			Add(inf);
			while (!back) {
				field SEARCH[2] = { "The vertex was added successfully", "Back" };
				if (menu(SEARCH, 2) == 1) back = 1;
			}
		}

		else if (choice == 4) {
			while (!back) {
				field GET[3] = { "Tree output based on Reverse_Inorder_traversal:" , "Back", "" };
				std::string res = "\n";
				Reverse_Inorder(res, pRoot);
				GET[2].name = res;
				if (menu(GET, 3) == 1) { back = 1; }
			}
		}

		else if (choice == 5) {
			while (!back) {
				field GET[3] = { "Inline output based on Preorder_traversal:" , "Back", "" };
				std::string res = "\n";
				Preorder_inline(res, pRoot);
				GET[2].name = res;
				if (menu(GET, 3) == 1) { back = 1; }
			}
		}

		else if (choice == 6) {
			int inf = stoi(Get_el_console("Enter a inf of vertex:"));
			Delete(inf);
			while (!back) {
				field DEL[2] = { str_delete, "Back" };
				if (menu(DEL, 2) == 1) back = 1;
			}
		}

		else if (choice == 7) {
			exit(0);
		}
	}
		
	
	return 0;
}

