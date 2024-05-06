#pragma once

#include <iomanip>
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;

const float start_left_x = -0.02f;
const float start_right_x = 0.07f;
const float start_up_y = 0.95f;
const float start_down_y = 0.85f;

const float k = 0.1;
const float v = 0.25;

struct point_position
{
	float x;
	float y;
};

using namespace std;

point_position drawLeftLine(float left_x, float down_y, float height) {

	point_position A;
	A.x = left_x - k * height;
	A.y = down_y - v;

	// Рисуем линию
	glBegin(GL_LINES);
	glVertex2f(left_x, down_y); // Нижняя левая вершина квадрата
	glVertex2f(A.x, A.y);
	glEnd();

	return A;
}

point_position drawRightLine(float right_x, float down_y, float height) {

	point_position B;
	B.x = right_x + k * height;
	B.y = down_y - v;

	// Рисуем линию
	glBegin(GL_LINES);
	glVertex2f(right_x, down_y); // Нижняя правая вершина квадрата
	glVertex2f(B.x, B.y);
	glEnd();

	return B;
}

void drawSquareWithNumber(float left_x, float right_x, float down_y, float up_y, double number) {

	float x = left_x + 0.01f;
	float y = down_y + 0.03f;

	std::ostringstream stream;
	stream << number;
	std::string numberString = stream.str();

	// Рисуем квадрат
	glColor3f(0.85, 0.85, 0.85); // Установливаем цвет на серый
	glBegin(GL_QUADS);
	glVertex2f(left_x, down_y);
	glVertex2f(right_x, down_y);
	glVertex2f(right_x, up_y);
	glVertex2f(left_x, up_y);
	glEnd();

	// Рисуем черную рамку вокруг квадрата.
	glColor3f(0.0, 0.0, 0.0); // Установливаем цвет на черный
	glBegin(GL_LINE_LOOP);
	glVertex2f(left_x, down_y);
	glVertex2f(right_x, down_y);
	glVertex2f(right_x, up_y);
	glVertex2f(left_x, up_y);
	glEnd();

	// рисуем число внутри квадрата
	glColor3f(0.0, 0.0, 0.0); // Установливаем цвет на черный
	glRasterPos2f(x, y);

	const char* numberChars = numberString.c_str();

	// Выводим каждый символ по очереди
	for (int i = 0; i < numberString.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numberChars[i]);
	}
}

class Node
{
private:
	double value;
	Node* left;
	Node* right;
	int height;
public:
	Node() {
		value = 0;
		left = nullptr;
		right = nullptr;
		height = 0;
	}
	Node(double value_) {
		value = value_;
		left = nullptr;
		right = nullptr;
		height = 0;
	}
	int get_height(Node* node) {
		return node == nullptr ? -1 : node->height;
	}
	void update_height(Node* node) {
		int max = get_height(node->left) > get_height(node->right) ? get_height(node->left) : get_height(node->right);
		node->height = max + 1;
	}
	int check_balance(Node* node) {
		return (node == nullptr) ? 0 : get_height(node->right) - get_height(node->left);
	}
	void swap(Node* a, Node* b) {
		double temp = a->value;
		a->value = b->value;
		b->value = temp;
	}
	void right_rotate(Node* node) {
		swap(node, node->left);
		Node* buffer = node->right;
		node->right = node->left;
		node->left = node->right->left;
		node->right->left = node->right->right;
		node->right->right = buffer;
		update_height(node->right);
		update_height(node);
	}
	void left_rotate(Node* node) {
		swap(node, node->right);
		Node* buffer = node->left;
		node->left = node->right;
		node->right = node->left->right;
		node->left->right = node->left->left;
		node->left->left = buffer;
		update_height(node->left);
		update_height(node);
	}
	void balance(Node* node) {
		int balance = check_balance(node);
		if (balance == -2) {
			if (check_balance(node->left) == 1) left_rotate(node->left);
			right_rotate(node);
		}
		else if (balance == 2) {
			if (check_balance(node->right) == -1) right_rotate(node->right);
			left_rotate(node);
		}
	}
	void insert(Node* node, const double value) {
		if (value < node->value) {
			if (node->left == nullptr) { node->left = new Node{ value }; }
			else { insert(node->left, value); }
		}
		else if (value > node->value) {
			if (node->right == nullptr) { node->right = new Node{ value }; }
			else { insert(node->right, value); }
		}
		update_height(node);
		balance(node);
	}
	Node* get_min(Node* node) {
		if (node == nullptr) { return nullptr; }

		if (node->left == nullptr) { return node; }
		else return get_min(node->left);
	}
	Node* get_max(Node* node) {
		if (node == nullptr) { return nullptr; }

		if (node->right == nullptr) { return node; }
		else return get_max(node->right);
	}
	Node* search(Node* node, const double value) {
		if (node == nullptr) { return nullptr; }

		if (node->value == value) { return node; }
		else {
			return (value < node->value) ? search(node->left, value) : search(node->right, value);
		}
	}
	Node* delete_node(Node* node, double value) {
		if (node == nullptr)
			return node;

		if (value < node->value)
			node->left = delete_node(node->left, value);
		else if (value > node->value)
			node->right = delete_node(node->right, value);
		else {
			if (node->left == nullptr || node->right == nullptr) {
				Node* temp = node;
				node = (node->left == nullptr) ? node->right : node->left;
				delete temp;
			}
			else {
				Node* min_right = get_min(node->right);
				node->value = min_right->value;
				node->right = delete_node(node->right, min_right->value);
			}
		}
		if (node != nullptr) {
			update_height(node);
			balance(node);
		}
		return node;
	}
	void print_symmetric(Node* node) {
		if (node == nullptr) { return; }

		print_symmetric(node->left);
		cout << node->value << " ";
		print_symmetric(node->right);
	}
	void print_reverse(Node* node) {
		if (node == nullptr) { return; }

		print_symmetric(node->left);
		print_symmetric(node->right);
		cout << node->value << " ";
	}
	void print_direct(Node* node) {
		if (node == nullptr) { return; }
		cout << node->value << " ";
		print_symmetric(node->left);
		print_symmetric(node->right);
	}
	void print_vertical(Node* node, int indent = 0, char branch = ' ') {
		if (node == nullptr)
			return;
		const int spaces = 4;
		print_vertical(node->right, indent + spaces, '/');
		cout << std::setw(indent) << ' ' << branch << node->value << "\n";
		print_vertical(node->left, indent + spaces, '\\');
	}
	void paint_tree(Node* node, float left_x, float right_x, float down_y, float up_y) {
		if (node != nullptr) {
			drawSquareWithNumber(left_x, right_x, down_y, up_y, node->value);
			if (node->left != nullptr) {
				point_position new_point_left = drawLeftLine(left_x, down_y, node->height);
				paint_tree(node->left, new_point_left.x - 0.05, new_point_left.x + 0.05, new_point_left.y - 0.1, new_point_left.y - 0.0);
			}
			if (node->right != nullptr) {
				point_position new_point_right = drawRightLine(right_x, down_y, node->height);
				paint_tree(node->right, new_point_right.x - 0.05, new_point_right.x + 0.05, new_point_right.y - 0.1, new_point_right.y - 0.0);
			}
		}
	}
};

