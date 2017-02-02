#include <functional>
#include <string>
#include <vector>

#include "SortStats.hpp"

bool compareVectors(std::vector<int> one, std::vector<int> two);
bool testCase1(std::function<SortStats(std::vector<int>&)> sortFunc);
bool testCase2(std::function<SortStats(std::vector<int>&)> sortFunc);
bool testCase3(std::function<SortStats(std::vector<int>&)> sortFunc);
bool testCaseCompare(std::function<SortStats(std::vector<int>&)> bubbleSortFunc, std::function<SortStats(std::vector<int>&)> selectSortFunc);

void executeTest(std::function<bool(std::function<SortStats(std::vector<int>&)>)> testCase, std::function<SortStats(std::vector<int>&)> sortFunc, std::string label);
void executeTest(std::function<bool(std::function<SortStats(std::vector<int>&)>, std::function<SortStats(std::vector<int>&)>)> testCase, std::function<SortStats(std::vector<int>&)> sortFuncA, std::function<SortStats(std::vector<int>&)> sortFuncB, std::string label);

const std::vector<std::vector<int> > unorderedVec = {
	std::vector<int>  {
		61, 64, 23, 13, 94, 39, 70, 78, 95, 12, 38, 2, 4, 58, 5, 56, 87, 17, 14, 65, 50, 90, 54, 29, 27, 92, 25, 96, 57, 72, 15, 48, 68, 6, 20, 62, 73, 32, 21, 67, 24, 83, 63, 81, 46, 60, 89, 82, 7, 100, 49, 42, 28, 53, 93, 10, 41, 88, 45, 3, 98, 1, 35, 22, 99, 75, 66, 97, 26, 71, 51, 37, 77, 16, 30, 76, 34, 85, 80, 86, 11, 19, 59, 36, 43, 44, 55, 9, 31, 33, 91, 84, 74, 40, 18, 52, 8, 79, 69, 47
	},

	std::vector<int> {
		148, 40, 161, 34, 146, 114, 106, 198, 177, 74, 67, 119, 129, 143, 182, 91, 3, 32, 75, 183, 158, 156, 44, 137, 118, 33, 197, 94, 8, 27, 48, 194, 69, 53, 112, 66, 29, 6, 193, 147, 154, 13, 115, 43, 192, 10, 36, 169, 80, 101, 125, 164, 110, 25, 7, 174, 2, 162, 184, 108, 168, 88, 81, 14, 62, 49, 85, 144, 59, 151, 181, 41, 5, 175, 117, 82, 58, 78, 39, 90, 17, 71, 188, 65, 166, 172, 11, 35, 18, 179, 103, 124, 76, 173, 159, 138, 77, 141, 111, 73, 130, 149, 122, 170, 60, 64, 38, 9, 72, 26, 123, 96, 87, 145, 63, 200, 150, 42, 19, 120, 1, 165, 98, 167, 4, 15, 105, 30, 68, 189, 47, 99, 126, 134, 46, 100, 16, 95, 196, 142, 127, 45, 52, 107, 121, 186, 155, 136, 50, 93, 23, 157, 176, 89, 104, 86, 28, 79, 84, 24, 140, 152, 12, 195, 131, 190, 160, 56, 22, 83, 102, 54, 116, 185, 55, 31, 133, 199, 132, 171, 70, 139, 153, 191, 92, 128, 61, 187, 163, 21, 180, 97, 109, 113, 135, 51, 178, 20, 37, 57
	},

	std::vector<int> {
		89, 29, 222, 298, 276, 79, 77, 197, 105, 38, 5, 74, 75, 47, 41, 21, 18, 143, 265, 104, 267, 268, 208, 214, 209, 167, 50, 270, 269, 257, 55, 80, 92, 282, 256, 221, 100, 186, 231, 275, 88, 65, 111, 291, 182, 192, 138, 118, 112, 207, 274, 83, 40, 78, 194, 171, 129, 294, 160, 125, 224, 49, 176, 124, 16, 6, 250, 68, 184, 132, 11, 3, 271, 113, 34, 84, 280, 36, 287, 235, 142, 168, 119, 141, 193, 103, 72, 158, 247, 117, 227, 8, 67, 27, 25, 161, 115, 70, 228, 97, 300, 144, 122, 258, 95, 260, 56, 150, 110, 229, 94, 76, 63, 51, 86, 152, 140, 210, 126, 180, 213, 71, 240, 52, 116, 204, 295, 297, 121, 249, 172, 37, 26, 108, 157, 2, 123, 279, 281, 28, 10, 153, 170, 73, 273, 232, 4, 131, 17, 201, 177, 195, 128, 185, 149, 23, 101, 252, 272, 57, 248, 285, 19, 233, 243, 166, 203, 102, 133, 134, 1, 43, 266, 90, 163, 145, 286, 139, 93, 42, 135, 264, 82, 137, 198, 64, 251, 130, 289, 200, 181, 296, 278, 183, 226, 91, 293, 174, 24, 202, 238, 242, 146, 263, 127, 58, 165, 216, 107, 241, 30, 9, 292, 169, 191, 53, 245, 178, 61, 15, 106, 114, 99, 20, 155, 62, 259, 85, 32, 39, 212, 254, 196, 225, 219, 81, 217, 199, 236, 48, 284, 299, 151, 136, 220, 59, 234, 13, 147, 156, 120, 211, 46, 223, 148, 215, 218, 187, 175, 179, 45, 35, 66, 54, 31, 44, 164, 14, 69, 253, 190, 239, 12, 22, 188, 237, 159, 283, 173, 98, 7, 230, 162, 205, 154, 109, 290, 87, 262, 288, 246, 60, 261, 189, 33, 244, 255, 277, 96, 206
	},

	std::vector<int> {
		303, 100, 126, 336, 199, 236, 105, 43, 206, 73, 90, 331, 1, 300, 309, 237, 92, 58, 26, 320, 247, 371, 232, 275, 3, 353, 244, 55, 49, 287, 64, 301, 295, 152, 11, 161, 115, 19, 192, 366, 194, 395, 229, 284, 79, 399, 60, 151, 317, 383, 389, 368, 72, 315, 69, 128, 278, 219, 171, 228, 96, 267, 140, 345, 292, 106, 111, 136, 188, 63, 375, 347, 257, 240, 208, 340, 274, 88, 266, 209, 255, 39, 28, 388, 220, 40, 57, 343, 245, 203, 373, 103, 342, 310, 71, 148, 333, 113, 172, 297, 318, 335, 204, 311, 380, 243, 252, 327, 272, 269, 89, 337, 122, 70, 213, 186, 308, 197, 169, 31, 108, 168, 84, 33, 254, 239, 193, 290, 190, 144, 4, 76, 313, 233, 285, 294, 178, 235, 382, 283, 156, 48, 379, 210, 167, 18, 34, 314, 201, 234, 304, 81, 139, 30, 364, 348, 306, 116, 27, 396, 87, 176, 35, 350, 264, 250, 258, 370, 385, 288, 248, 381, 222, 164, 322, 224, 225, 253, 112, 56, 299, 202, 376, 125, 356, 52, 119, 135, 53, 37, 230, 83, 332, 75, 2, 133, 307, 189, 312, 91, 329, 221, 137, 129, 217, 66, 98, 68, 378, 212, 180, 214, 393, 372, 276, 8, 277, 143, 354, 134, 155, 47, 362, 263, 392, 377, 154, 6, 207, 391, 61, 293, 67, 41, 271, 86, 62, 181, 270, 36, 216, 365, 45, 359, 281, 256, 289, 46, 162, 102, 374, 50, 14, 324, 349, 316, 325, 261, 77, 226, 215, 302, 346, 82, 394, 338, 32, 259, 65, 163, 386, 384, 44, 341, 146, 363, 184, 147, 12, 157, 286, 114, 227, 246, 85, 80, 94, 175, 170, 191, 268, 182, 251, 358, 218, 165, 166, 179, 183, 249, 242, 280, 330, 223, 158, 279, 159, 120, 334, 51, 121, 38, 196, 110, 323, 231, 369, 339, 104, 265, 200, 123, 132, 118, 153, 305, 127, 20, 355, 205, 97, 150, 16, 198, 59, 117, 211, 328, 138, 23, 21, 398, 10, 15, 387, 99, 29, 54, 22, 107, 241, 101, 195, 326, 187, 367, 174, 321, 177, 17, 142, 160, 238, 282, 262, 360, 291, 95, 352, 319, 260, 185, 390, 357, 397, 344, 13, 124, 24, 5, 74, 131, 130, 7, 78, 273, 145, 400, 25, 173, 109, 141, 298, 351, 93, 361, 149, 296, 42, 9
	},

	std::vector<int> {
		374, 325, 286, 384, 382, 388, 83, 8, 30, 177, 31, 242, 151, 91, 405, 25, 10, 106, 433, 148, 420, 9, 429, 461, 263, 181, 389, 102, 372, 123, 385, 140, 77, 100, 202, 227, 204, 308, 363, 445, 37, 484, 392, 276, 334, 331, 42, 62, 26, 17, 297, 199, 295, 183, 104, 224, 120, 155, 467, 19, 408, 239, 66, 460, 490, 3, 438, 300, 133, 167, 84, 356, 403, 302, 197, 234, 64, 222, 381, 166, 251, 447, 161, 249, 212, 455, 18, 131, 233, 290, 180, 20, 292, 216, 55, 370, 386, 469, 347, 70, 285, 209, 470, 191, 264, 168, 240, 259, 160, 15, 265, 39, 387, 208, 125, 367, 310, 178, 418, 24, 393, 423, 127, 130, 278, 406, 4, 435, 327, 472, 147, 332, 107, 153, 439, 352, 454, 230, 174, 213, 349, 237, 417, 471, 489, 345, 228, 221, 53, 369, 175, 299, 135, 261, 2, 188, 453, 41, 498, 23, 294, 59, 414, 5, 117, 486, 269, 371, 309, 90, 219, 466, 383, 214, 96, 28, 154, 257, 94, 279, 283, 398, 121, 344, 434, 274, 200, 170, 465, 22, 51, 44, 142, 29, 260, 57, 203, 351, 152, 109, 313, 79, 338, 112, 12, 226, 85, 451, 185, 16, 258, 157, 205, 350, 206, 54, 442, 296, 394, 348, 452, 89, 495, 337, 210, 378, 171, 416, 355, 40, 430, 458, 456, 326, 74, 223, 359, 101, 500, 457, 320, 190, 448, 329, 425, 473, 305, 141, 480, 373, 235, 485, 248, 432, 162, 450, 483, 330, 266, 364, 165, 78, 6, 357, 407, 333, 173, 75, 65, 396, 464, 497, 277, 61, 354, 179, 144, 63, 409, 193, 311, 256, 136, 492, 444, 87, 496, 145, 391, 52, 232, 34, 111, 38, 229, 252, 343, 80, 499, 211, 287, 36, 267, 82, 33, 236, 245, 182, 360, 476, 139, 150, 317, 474, 362, 488, 92, 446, 411, 114, 353, 404, 304, 164, 243, 419, 255, 68, 128, 241, 156, 195, 86, 328, 493, 13, 478, 116, 316, 189, 494, 415, 98, 340, 428, 303, 335, 103, 250, 280, 275, 196, 268, 400, 201, 342, 397, 421, 462, 149, 482, 50, 27, 410, 323, 281, 97, 176, 441, 358, 207, 377, 169, 187, 390, 71, 143, 306, 254, 272, 126, 134, 321, 324, 368, 137, 346, 270, 375, 481, 401, 291, 88, 293, 129, 49, 32, 146, 459, 244, 376, 440, 72, 284, 238, 318, 218, 312, 322, 487, 186, 132, 56, 477, 172, 437, 282, 198, 122, 289, 138, 426, 225, 395, 298, 246, 48, 262, 159, 35, 379, 115, 73, 315, 14, 105, 307, 220, 7, 45, 449, 271, 110, 443, 319, 113, 431, 158, 21, 11, 46, 184, 163, 47, 93, 475, 427, 1, 468, 402, 422, 194, 361, 399, 413, 81, 253, 365, 336, 108, 67, 76, 463, 339, 95, 288, 217, 314, 215, 231, 58, 99, 424, 436, 341, 119, 60, 301, 192, 479, 491, 118, 366, 43, 69, 412, 273, 247, 124, 380
	},

	std::vector<int> {
		304, 19, 311, 252, 267, 107, 286, 130, 378, 214, 347, 188, 185, 566, 192, 498, 196, 126, 121, 101, 335, 67, 467, 9, 288, 220, 343, 525, 341, 135, 321, 104, 197, 254, 191, 111, 319, 499, 232, 138, 392, 377, 357, 585, 468, 98, 494, 95, 221, 432, 579, 349, 257, 550, 75, 370, 236, 170, 444, 26, 352, 291, 79, 282, 206, 397, 413, 297, 455, 365, 57, 68, 532, 90, 353, 337, 85, 12, 312, 362, 203, 471, 72, 588, 521, 158, 284, 60, 546, 390, 582, 186, 35, 231, 136, 157, 285, 165, 29, 190, 151, 14, 77, 169, 48, 465, 65, 86, 393, 480, 415, 233, 410, 1, 228, 305, 38, 28, 119, 493, 280, 439, 175, 515, 207, 42, 336, 262, 10, 89, 150, 324, 155, 429, 442, 198, 204, 431, 209, 103, 323, 528, 129, 358, 445, 581, 481, 63, 453, 106, 447, 333, 426, 492, 542, 371, 318, 388, 22, 530, 66, 584, 62, 510, 450, 382, 134, 419, 217, 215, 330, 164, 384, 560, 59, 120, 176, 205, 500, 102, 517, 275, 564, 403, 549, 486, 143, 551, 50, 123, 292, 512, 342, 554, 595, 241, 520, 470, 37, 47, 173, 435, 301, 361, 597, 11, 592, 524, 99, 477, 118, 596, 557, 513, 295, 434, 52, 406, 182, 310, 430, 380, 216, 41, 248, 593, 519, 53, 189, 385, 484, 359, 202, 334, 466, 279, 367, 485, 373, 144, 142, 226, 199, 208, 569, 133, 308, 244, 281, 276, 251, 313, 289, 339, 331, 354, 543, 91, 181, 394, 417, 526, 381, 427, 45, 31, 559, 193, 194, 213, 563, 396, 27, 168, 401, 469, 49, 105, 249, 113, 269, 247, 258, 180, 414, 218, 332, 92, 420, 472, 235, 350, 160, 223, 548, 261, 277, 544, 340, 516, 240, 424, 23, 449, 283, 404, 558, 320, 398, 545, 265, 328, 507, 600, 314, 212, 167, 234, 15, 3, 112, 425, 55, 293, 511, 338, 122, 179, 96, 591, 58, 402, 25, 137, 139, 127, 568, 478, 229, 39, 527, 290, 325, 117, 34, 506, 387, 400, 508, 395, 32, 421, 552, 456, 441, 178, 110, 78, 225, 438, 162, 446, 255, 302, 574, 590, 458, 124, 407, 547, 348, 495, 140, 575, 154, 46, 553, 128, 565, 474, 573, 40, 8, 5, 567, 294, 488, 80, 502, 322, 4, 376, 171, 108, 17, 509, 88, 303, 174, 360, 183, 408, 317, 299, 76, 298, 578, 195, 230, 433, 69, 491, 443, 152, 463, 153, 253, 345, 43, 87, 344, 416, 300, 116, 536, 256, 583, 264, 518, 287, 239, 20, 100, 82, 243, 479, 237, 33, 389, 379, 270, 501, 54, 201, 572, 346, 238, 534, 274, 13, 166, 454, 44, 428, 541, 533, 51, 18, 405, 70, 452, 589, 132, 187, 211, 418, 505, 200, 97, 374, 409, 473, 451, 177, 156, 522, 36, 576, 487, 83, 30, 7, 586, 278, 436, 383, 356, 537, 327, 273, 412, 93, 562, 268, 448, 250, 21, 580, 125, 2, 145, 457, 461, 372, 464, 161, 363, 73, 263, 411, 272, 64, 459, 61, 598, 16, 555, 422, 56, 460, 368, 475, 594, 224, 148, 84, 538, 149, 587, 489, 577, 245, 210, 172, 163, 219, 329, 364, 523, 366, 369, 476, 222, 296, 482, 556, 497, 260, 423, 74, 490, 159, 6, 462, 94, 24, 571, 246, 271, 399, 141, 71, 540, 531, 309, 184, 504, 259, 599, 147, 503, 315, 514, 266, 109, 146, 306, 131, 440, 529, 496, 570, 391, 227, 307, 242, 81, 535, 375, 326, 437, 114, 316, 351, 386, 483, 561, 355, 539, 115
	},

	std::vector<int> {
		195, 261, 305, 249, 182, 173, 657, 433, 652, 632, 141, 16, 41, 549, 367, 591, 72, 17, 572, 105, 452, 457, 226, 8, 73, 516, 194, 318, 443, 700, 82, 512, 19, 272, 401, 525, 45, 126, 229, 307, 120, 501, 454, 374, 608, 258, 266, 127, 465, 20, 101, 524, 685, 411, 90, 150, 651, 111, 599, 623, 462, 333, 565, 640, 40, 352, 190, 403, 644, 361, 662, 302, 390, 264, 634, 295, 500, 286, 76, 533, 553, 407, 179, 278, 671, 67, 543, 437, 617, 619, 156, 63, 382, 649, 44, 125, 507, 255, 667, 124, 673, 547, 139, 300, 598, 142, 418, 329, 389, 159, 555, 58, 29, 35, 449, 422, 164, 345, 233, 177, 664, 357, 409, 530, 520, 471, 236, 203, 152, 251, 475, 415, 241, 659, 569, 94, 145, 100, 498, 606, 161, 495, 487, 517, 268, 254, 580, 245, 622, 174, 504, 325, 256, 297, 513, 687, 299, 306, 1, 189, 238, 356, 215, 183, 510, 56, 438, 260, 522, 528, 216, 670, 334, 600, 593, 118, 196, 267, 402, 187, 425, 514, 368, 163, 463, 587, 479, 693, 60, 637, 378, 166, 588, 459, 301, 244, 336, 207, 199, 79, 412, 162, 193, 612, 86, 14, 119, 554, 116, 34, 247, 625, 192, 458, 290, 328, 346, 175, 98, 359, 694, 57, 416, 320, 665, 137, 515, 153, 536, 349, 375, 33, 485, 607, 88, 358, 201, 541, 42, 332, 439, 455, 167, 237, 322, 611, 317, 432, 353, 224, 138, 426, 519, 679, 523, 496, 568, 380, 464, 243, 624, 697, 583, 53, 92, 494, 410, 453, 315, 176, 11, 470, 140, 610, 220, 638, 99, 169, 180, 417, 271, 240, 87, 277, 310, 54, 49, 113, 615, 335, 257, 242, 181, 440, 385, 499, 627, 405, 468, 69, 684, 576, 531, 366, 197, 398, 230, 526, 89, 21, 348, 480, 506, 28, 585, 350, 227, 108, 210, 492, 341, 445, 344, 413, 388, 503, 596, 408, 628, 573, 80, 32, 48, 27, 287, 146, 669, 539, 31, 534, 613, 231, 24, 489, 683, 699, 630, 691, 50, 682, 581, 561, 151, 370, 635, 130, 61, 586, 186, 381, 648, 618, 535, 594, 689, 377, 490, 15, 311, 39, 478, 103, 360, 419, 435, 477, 363, 55, 639, 484, 646, 158, 631, 312, 323, 590, 521, 395, 429, 427, 198, 354, 675, 276, 165, 666, 577, 502, 303, 52, 23, 658, 214, 296, 379, 110, 482, 544, 537, 592, 493, 602, 282, 64, 527, 3, 232, 369, 291, 603, 148, 339, 384, 298, 259, 84, 509, 629, 575, 540, 144, 678, 70, 288, 391, 65, 275, 115, 136, 394, 222, 677, 285, 486, 695, 469, 552, 595, 75, 355, 571, 383, 294, 601, 248, 81, 253, 460, 211, 78, 676, 578, 326, 508, 688, 696, 83, 448, 250, 444, 133, 184, 661, 643, 387, 327, 365, 347, 645, 13, 567, 95, 171, 316, 26, 309, 557, 393, 654, 129, 9, 456, 246, 604, 430, 641, 364, 570, 473, 324, 542, 421, 447, 446, 293, 597, 548, 235, 208, 30, 636, 668, 582, 466, 106, 589, 406, 104, 488, 135, 273, 134, 212, 219, 262, 472, 467, 7, 450, 420, 217, 269, 434, 319, 313, 397, 340, 474, 614, 441, 114, 132, 518, 68, 97, 392, 178, 221, 686, 107, 200, 653, 122, 538, 38, 372, 647, 551, 206, 314, 491, 362, 155, 633, 289, 25, 584, 59, 559, 692, 556, 371, 263, 529, 168, 213, 22, 342, 96, 239, 605, 234, 62, 218, 308, 279, 400, 223, 476, 621, 123, 117, 202, 423, 109, 160, 656, 46, 609, 566, 112, 373, 650, 550, 74, 414, 128, 10, 436, 71, 545, 698, 505, 265, 337, 574, 270, 620, 292, 66, 563, 121, 149, 672, 386, 12, 284, 252, 77, 47, 225, 660, 4, 404, 399, 143, 579, 532, 564, 424, 91, 351, 209, 680, 396, 228, 376, 343, 191, 204, 642, 338, 102, 2, 663, 188, 205, 280, 558, 281, 36, 428, 616, 157, 481, 147, 43, 6, 451, 461, 283, 681, 131, 497, 37, 560, 331, 304, 330, 321, 690, 626, 655, 5, 674, 93, 170, 562, 511, 483, 154, 172, 18, 431, 185, 51, 442, 546, 274, 85
	},

	std::vector<int> {
		481, 593, 83, 566, 789, 563, 4, 799, 776, 287, 139, 45, 332, 781, 212, 642, 671, 340, 665, 373, 100, 398, 303, 731, 510, 578, 352, 722, 61, 409, 334, 35, 504, 241, 594, 326, 279, 758, 666, 741, 319, 651, 703, 591, 304, 441, 540, 493, 81, 377, 786, 744, 53, 380, 141, 426, 101, 616, 568, 191, 561, 684, 710, 630, 482, 385, 619, 58, 376, 501, 434, 667, 89, 447, 131, 439, 242, 387, 202, 227, 120, 220, 515, 2, 57, 488, 670, 286, 437, 587, 784, 366, 474, 661, 410, 285, 7, 432, 381, 535, 247, 412, 1, 76, 780, 84, 708, 62, 164, 486, 250, 15, 695, 296, 275, 451, 571, 181, 448, 771, 539, 204, 465, 469, 136, 274, 272, 311, 746, 265, 174, 284, 291, 379, 306, 102, 351, 457, 762, 769, 151, 292, 383, 94, 720, 794, 207, 122, 742, 66, 229, 192, 734, 798, 112, 171, 221, 363, 407, 458, 298, 638, 187, 413, 404, 596, 263, 480, 72, 584, 31, 193, 248, 175, 517, 176, 255, 747, 680, 620, 14, 635, 595, 87, 19, 80, 614, 337, 36, 752, 276, 423, 168, 143, 162, 348, 766, 382, 256, 218, 92, 389, 135, 697, 350, 526, 496, 314, 20, 553, 463, 558, 289, 645, 295, 484, 416, 127, 146, 445, 712, 130, 318, 103, 608, 288, 86, 650, 225, 706, 754, 346, 507, 453, 499, 435, 785, 677, 188, 655, 555, 476, 260, 374, 183, 148, 106, 269, 577, 737, 531, 724, 55, 85, 324, 592, 281, 51, 640, 629, 153, 375, 497, 719, 711, 757, 206, 523, 792, 140, 258, 686, 59, 37, 649, 611, 316, 514, 203, 341, 261, 126, 355, 320, 114, 598, 370, 646, 657, 21, 585, 244, 97, 494, 693, 658, 612, 466, 394, 554, 359, 542, 302, 329, 503, 718, 77, 160, 43, 123, 327, 189, 29, 450, 249, 47, 438, 34, 259, 216, 527, 774, 685, 105, 548, 632, 78, 664, 547, 215, 726, 688, 75, 113, 444, 604, 13, 356, 787, 609, 739, 186, 378, 158, 177, 190, 195, 793, 755, 290, 607, 454, 65, 345, 427, 512, 79, 155, 613, 492, 778, 764, 698, 98, 652, 590, 330, 217, 442, 406, 606, 125, 756, 433, 343, 74, 16, 185, 200, 576, 575, 692, 25, 253, 570, 41, 729, 505, 730, 308, 172, 588, 617, 544, 231, 682, 485, 305, 299, 715, 529, 699, 740, 489, 104, 349, 243, 307, 795, 294, 222, 262, 328, 765, 743, 22, 634, 170, 534, 99, 233, 676, 342, 491, 663, 721, 562, 421, 479, 749, 226, 615, 659, 390, 23, 767, 395, 621, 384, 44, 477, 639, 402, 297, 583, 396, 704, 115, 154, 516, 782, 790, 580, 157, 277, 361, 791, 449, 520, 268, 470, 107, 323, 138, 64, 178, 713, 625, 550, 673, 502, 273, 506, 648, 738, 556, 364, 211, 10, 96, 201, 219, 166, 631, 452, 180, 490, 759, 63, 108, 42, 683, 681, 728, 783, 455, 636, 610, 411, 672, 147, 461, 73, 624, 152, 430, 586, 245, 763, 468, 532, 464, 393, 678, 353, 723, 12, 431, 397, 524, 557, 508, 321, 360, 689, 60, 271, 405, 569, 325, 736, 70, 626, 371, 9, 239, 536, 32, 33, 367, 687, 331, 403, 788, 779, 618, 95, 49, 313, 194, 800, 543, 694, 46, 40, 768, 224, 419, 251, 538, 415, 137, 184, 270, 145, 368, 278, 675, 399, 293, 88, 521, 197, 733, 336, 525, 6, 386, 109, 582, 522, 232, 173, 67, 429, 165, 254, 149, 317, 338, 656, 133, 347, 339, 717, 234, 301, 335, 11, 459, 603, 372, 498, 772, 714, 727, 511, 391, 159, 574, 597, 163, 751, 300, 119, 208, 56, 572, 424, 735, 365, 601, 533, 142, 357, 408, 417, 90, 240, 428, 93, 551, 495, 654, 641, 124, 167, 549, 530, 573, 705, 228, 472, 709, 156, 509, 209, 797, 662, 26, 637, 344, 267, 691, 400, 753, 707, 68, 196, 564, 223, 333, 471, 401, 777, 182, 565, 264, 456, 199, 118, 644, 27, 750, 52, 236, 500, 24, 310, 627, 702, 392, 129, 28, 18, 462, 700, 567, 420, 589, 266, 473, 716, 5, 599, 134, 8, 559, 315, 362, 30, 69, 669, 252, 369, 674, 354, 48, 205, 246, 230, 257, 579, 643, 82, 38, 633, 280, 701, 418, 528, 773, 518, 446, 214, 475, 422, 653, 725, 460, 546, 282, 796, 602, 519, 545, 39, 309, 732, 647, 283, 17, 775, 161, 54, 770, 760, 150, 358, 628, 696, 237, 144, 210, 581, 322, 91, 560, 198, 513, 761, 537, 425, 179, 238, 600, 235, 50, 440, 668, 541, 436, 414, 660, 213, 467, 121, 443, 745, 128, 312, 748, 132, 110, 111, 117, 388, 3, 487, 483, 605, 552, 623, 116, 169, 71, 690, 679, 478, 622
	},

	std::vector<int> {
		463, 691, 728, 859, 808, 168, 259, 561, 830, 77, 553, 760, 457, 131, 198, 20, 560, 50, 390, 871, 626, 619, 704, 238, 725, 293, 850, 743, 363, 161, 661, 400, 686, 415, 61, 602, 182, 331, 460, 324, 156, 756, 822, 125, 366, 518, 139, 653, 516, 223, 351, 708, 807, 687, 481, 654, 665, 546, 394, 230, 745, 662, 236, 802, 449, 374, 216, 861, 682, 270, 596, 271, 107, 287, 464, 187, 847, 605, 893, 212, 508, 703, 639, 398, 794, 429, 502, 55, 219, 797, 490, 673, 513, 323, 646, 806, 52, 277, 208, 318, 109, 126, 233, 113, 641, 627, 658, 285, 769, 755, 614, 569, 487, 798, 527, 707, 688, 413, 218, 817, 643, 310, 295, 669, 695, 167, 196, 356, 759, 844, 475, 521, 751, 500, 866, 585, 841, 173, 90, 523, 224, 613, 855, 465, 575, 484, 203, 360, 542, 15, 405, 737, 754, 114, 886, 98, 788, 201, 530, 377, 79, 877, 10, 317, 562, 86, 589, 345, 671, 551, 898, 494, 67, 428, 88, 793, 140, 172, 327, 456, 868, 35, 433, 568, 222, 154, 49, 891, 763, 672, 409, 30, 160, 573, 14, 795, 137, 191, 714, 446, 149, 9, 438, 252, 399, 358, 426, 659, 440, 210, 115, 406, 770, 577, 1, 176, 515, 305, 480, 852, 667, 145, 479, 215, 51, 411, 442, 890, 7, 809, 32, 177, 275, 315, 571, 430, 636, 352, 833, 353, 371, 721, 644, 33, 188, 895, 826, 624, 120, 169, 42, 16, 380, 101, 265, 330, 697, 618, 209, 282, 827, 599, 689, 268, 774, 541, 227, 301, 471, 159, 445, 591, 410, 899, 343, 772, 128, 735, 130, 340, 395, 474, 26, 272, 53, 576, 248, 493, 718, 836, 497, 240, 864, 253, 702, 237, 361, 458, 854, 657, 771, 165, 404, 221, 753, 134, 207, 620, 681, 60, 477, 730, 900, 663, 594, 291, 813, 742, 839, 175, 158, 232, 719, 290, 883, 121, 777, 739, 355, 217, 102, 419, 535, 373, 783, 634, 396, 74, 630, 70, 423, 350, 699, 722, 862, 706, 132, 758, 851, 76, 302, 621, 242, 143, 799, 726, 882, 469, 764, 279, 499, 382, 171, 600, 326, 840, 556, 588, 845, 368, 329, 635, 22, 489, 846, 670, 740, 678, 716, 87, 73, 828, 892, 803, 23, 498, 103, 597, 837, 548, 334, 821, 220, 592, 41, 570, 364, 257, 485, 181, 427, 590, 511, 148, 27, 312, 206, 717, 403, 720, 656, 520, 162, 578, 812, 308, 281, 680, 563, 752, 123, 349, 544, 274, 267, 174, 472, 370, 393, 105, 532, 584, 392, 239, 533, 256, 476, 189, 746, 384, 344, 607, 510, 378, 362, 72, 566, 506, 543, 736, 68, 881, 536, 383, 288, 250, 444, 825, 810, 768, 856, 56, 875, 229, 496, 376, 322, 44, 262, 724, 896, 557, 470, 761, 402, 554, 696, 731, 565, 226, 58, 779, 104, 202, 504, 319, 192, 617, 62, 335, 503, 354, 417, 468, 773, 781, 47, 609, 547, 54, 528, 75, 367, 255, 320, 647, 796, 675, 710, 645, 848, 200, 36, 4, 550, 767, 478, 94, 452, 738, 860, 579, 321, 625, 831, 414, 622, 135, 29, 603, 863, 791, 298, 372, 296, 425, 124, 749, 712, 37, 787, 316, 823, 683, 889, 757, 785, 642, 214, 5, 581, 842, 179, 243, 804, 347, 820, 525, 231, 163, 582, 762, 261, 580, 786, 190, 228, 89, 789, 501, 24, 241, 108, 488, 748, 341, 652, 416, 684, 40, 616, 705, 640, 263, 127, 258, 369, 119, 71, 300, 184, 12, 136, 244, 28, 747, 744, 872, 278, 314, 679, 880, 66, 95, 432, 337, 180, 311, 150, 247, 482, 99, 549, 18, 507, 534, 734, 564, 829, 386, 711, 870, 537, 284, 648, 633, 357, 117, 832, 21, 213, 732, 834, 133, 178, 448, 116, 153, 280, 43, 632, 638, 606, 790, 155, 884, 552, 574, 655, 628, 816, 306, 651, 69, 765, 64, 303, 778, 401, 545, 138, 462, 389, 46, 92, 660, 254, 782, 144, 157, 65, 461, 195, 815, 801, 766, 385, 388, 63, 170, 780, 608, 346, 876, 11, 858, 197, 379, 249, 234, 412, 538, 623, 454, 420, 332, 38, 838, 835, 700, 91, 342, 519, 750, 147, 676, 82, 637, 84, 183, 292, 559, 185, 264, 693, 57, 111, 245, 572, 225, 436, 784, 466, 408, 874, 610, 629, 843, 805, 422, 792, 649, 81, 867, 6, 304, 879, 849, 853, 522, 539, 524, 407, 865, 690, 598, 668, 299, 146, 17, 80, 260, 365, 531, 118, 100, 48, 328, 733, 2, 186, 615, 205, 604, 85, 211, 273, 593, 459, 698, 824, 336, 729, 492, 437, 204, 96, 776, 294, 434, 595, 885, 375, 612, 601, 505, 467, 421, 509, 97, 45, 631, 251, 447, 811, 587, 194, 701, 142, 727, 453, 800, 431, 246, 819, 8, 814, 235, 110, 818, 397, 558, 878, 359, 664, 741, 897, 418, 674, 473, 129, 3, 193, 455, 526, 692, 451, 297, 424, 443, 164, 894, 441, 583, 325, 887, 387, 567, 269, 93, 723, 266, 391, 78, 529, 25, 348, 517, 112, 677, 313, 775, 151, 34, 650, 540, 31, 199, 666, 289, 694, 83, 715, 283, 276, 450, 857, 122, 709, 339, 888, 713, 106, 514, 19, 13, 555, 39, 152, 338, 309, 483, 611, 869, 685, 512, 141, 495, 439, 166, 586, 381, 333, 307, 491, 873, 435, 286, 59, 486
	},

	std::vector<int> {
		314, 995, 389, 886, 535, 627, 247, 27, 670, 306, 692, 291, 819, 650, 19, 85, 611, 607, 552, 686, 395, 928, 628, 23, 800, 1000, 785, 902, 132, 244, 2, 476, 825, 648, 772, 580, 859, 310, 916, 302, 744, 741, 564, 95, 679, 158, 847, 632, 76, 794, 751, 238, 39, 898, 504, 835, 863, 419, 715, 790, 135, 765, 180, 784, 710, 972, 254, 20, 588, 897, 646, 408, 474, 460, 714, 48, 943, 186, 164, 726, 737, 352, 749, 429, 399, 985, 83, 472, 89, 577, 813, 803, 498, 131, 926, 823, 718, 321, 428, 616, 770, 214, 142, 191, 840, 929, 91, 808, 844, 292, 264, 220, 544, 249, 72, 257, 540, 272, 346, 229, 297, 329, 26, 798, 299, 412, 362, 740, 836, 226, 147, 978, 958, 111, 387, 443, 477, 488, 700, 805, 1, 531, 309, 307, 353, 987, 305, 122, 645, 280, 452, 437, 829, 810, 782, 67, 621, 811, 724, 619, 440, 912, 917, 795, 906, 974, 786, 613, 338, 173, 787, 574, 915, 933, 994, 846, 905, 79, 878, 685, 316, 579, 228, 492, 986, 748, 75, 500, 939, 436, 925, 984, 463, 426, 547, 521, 163, 930, 179, 325, 160, 146, 827, 702, 837, 213, 849, 502, 699, 159, 320, 237, 571, 511, 788, 4, 543, 334, 278, 548, 885, 602, 239, 982, 781, 337, 485, 694, 441, 866, 695, 566, 381, 720, 80, 438, 778, 256, 818, 608, 322, 199, 597, 444, 556, 537, 601, 152, 462, 170, 253, 977, 128, 138, 957, 149, 585, 821, 181, 363, 374, 891, 130, 203, 534, 545, 33, 719, 640, 809, 967, 983, 499, 418, 50, 112, 315, 729, 634, 150, 515, 622, 578, 332, 6, 761, 145, 484, 797, 86, 279, 843, 401, 405, 941, 615, 658, 74, 402, 415, 59, 16, 126, 115, 990, 899, 308, 496, 704, 858, 636, 434, 43, 913, 471, 169, 11, 208, 951, 335, 382, 456, 333, 865, 612, 705, 475, 758, 183, 517, 344, 673, 774, 15, 882, 375, 894, 773, 202, 510, 243, 889, 445, 681, 417, 355, 348, 793, 391, 354, 970, 300, 529, 397, 935, 953, 831, 53, 376, 328, 326, 78, 119, 731, 407, 287, 28, 981, 760, 605, 945, 347, 641, 512, 596, 32, 453, 706, 869, 779, 962, 466, 523, 875, 801, 872, 756, 319, 88, 222, 467, 464, 630, 339, 489, 184, 832, 775, 647, 36, 194, 274, 486, 368, 468, 185, 246, 952, 924, 282, 660, 304, 97, 252, 595, 361, 211, 54, 430, 10, 656, 901, 750, 404, 728, 317, 542, 196, 409, 295, 874, 532, 105, 946, 447, 204, 358, 522, 18, 895, 625, 620, 743, 665, 766, 845, 168, 654, 965, 271, 209, 461, 281, 84, 101, 171, 190, 753, 108, 349, 248, 318, 572, 356, 976, 862, 290, 231, 7, 133, 870, 137, 49, 120, 520, 684, 298, 659, 323, 514, 992, 193, 736, 908, 47, 360, 569, 154, 861, 880, 644, 410, 722, 555, 195, 143, 110, 868, 816, 153, 285, 370, 789, 289, 558, 423, 69, 117, 232, 96, 197, 312, 707, 739, 327, 479, 934, 662, 493, 690, 991, 833, 759, 626, 586, 46, 954, 893, 340, 919, 807, 914, 528, 570, 960, 283, 657, 311, 157, 637, 113, 590, 822, 273, 824, 850, 102, 680, 851, 921, 688, 136, 944, 288, 218, 155, 459, 716, 712, 834, 996, 234, 717, 270, 672, 568, 940, 343, 255, 776, 251, 693, 45, 806, 134, 266, 867, 969, 910, 431, 398, 166, 367, 708, 369, 13, 561, 241, 250, 73, 174, 212, 890, 371, 277, 696, 907, 509, 421, 884, 420, 518, 494, 449, 746, 379, 221, 446, 359, 478, 575, 742, 107, 378, 589, 432, 206, 491, 525, 424, 723, 814, 508, 60, 330, 624, 725, 258, 614, 989, 12, 121, 442, 609, 752, 667, 156, 669, 881, 433, 576, 873, 172, 735, 524, 852, 783, 336, 245, 483, 390, 235, 365, 562, 455, 663, 677, 956, 802, 856, 664, 388, 689, 103, 857, 606, 599, 804, 903, 968, 392, 422, 267, 284, 516, 480, 106, 37, 34, 207, 594, 192, 124, 187, 600, 385, 927, 384, 959, 581, 458, 269, 678, 762, 380, 205, 454, 240, 975, 757, 56, 923, 469, 200, 980, 236, 961, 854, 738, 435, 546, 631, 58, 165, 639, 70, 394, 473, 22, 118, 587, 730, 682, 44, 17, 950, 178, 497, 652, 709, 799, 661, 230, 189, 470, 303, 377, 260, 99, 31, 904, 671, 971, 351, 618, 262, 942, 754, 104, 94, 141, 721, 767, 505, 64, 703, 373, 182, 225, 261, 888, 623, 35, 77, 780, 820, 791, 638, 554, 57, 224, 553, 8, 313, 963, 887, 144, 448, 691, 683, 366, 642, 151, 841, 828, 701, 591, 733, 584, 563, 764, 123, 242, 490, 842, 341, 839, 815, 109, 61, 127, 698, 506, 416, 559, 792, 286, 331, 860, 997, 643, 55, 838, 937, 296, 92, 5, 649, 973, 948, 536, 755, 911, 403, 265, 635, 427, 711, 217, 533, 425, 947, 223, 713, 769, 993, 188, 519, 167, 38, 219, 125, 345, 666, 583, 411, 653, 383, 481, 988, 116, 513, 745, 922, 848, 539, 629, 82, 162, 876, 687, 651, 175, 633, 955, 451, 201, 932, 65, 457, 734, 592, 879, 541, 24, 3, 148, 826, 674, 51, 864, 268, 777, 964, 413, 342, 727, 233, 909, 294, 140, 87, 598, 487, 482, 42, 877, 357, 896, 979, 999, 62, 920, 9, 817, 538, 560, 949, 747, 551, 501, 732, 966, 324, 771, 30, 161, 81, 301, 550, 114, 350, 557, 998, 400, 275, 938, 216, 93, 25, 796, 617, 830, 573, 98, 768, 259, 68, 90, 883, 372, 386, 855, 495, 41, 676, 675, 139, 931, 66, 406, 176, 655, 527, 71, 530, 668, 215, 177, 227, 763, 198, 63, 29, 871, 567, 396, 210, 414, 853, 364, 549, 263, 439, 100, 52, 918, 14, 900, 276, 393, 892, 507, 936, 450, 40, 129, 603, 582, 697, 526, 604, 503, 565, 465, 610, 593, 21, 293, 812
	}
};
