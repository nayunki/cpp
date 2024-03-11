#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & obj) {
    *this = obj;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & obj) {
    (void)obj;
    return *this;
}

PmergeMe::~PmergeMe() {}

const char *PmergeMe::invalidInput::what() const throw() {
	return "Invalid Input";
}

void PmergeMe::printVector(std::vector<int> vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque() {
    for (size_t i = 0; i < argDeq.size(); i++) {
        std::cout << argDeq[i] << " ";
    }
    std::cout << std::endl;   
}

void PmergeMe::putArgToCtn(char **argv) {
    for (size_t i = 1; argv[i]; i++) {
        this->arg.push_back(argv[i]); // char *
    }

    int tmp;
    for (size_t i = 0; i < arg.size(); i++) {
        tmp = static_cast<int>(strtod(arg[i], NULL));
        if (tmp <= 0)
            throw invalidInput();
        this->argVec.push_back(tmp);
        this->argDeq.push_back(tmp);
    }
}

void PmergeMe::execute(char **argv) {
    putArgToCtn(argv);
    std::cout << "Before: ";
    printVector(argVec);

    clock_t start = clock();
    sortVector();
    clock_t fin = clock();
    vecTime = static_cast<double>(fin - start);

    std::cout << "After: ";
    printVector(mainVec);

/*
    for (size_t i = 0; argVec.size(); i++) {
        std::cout << argVec[i] << " ";
    }
    std::cout << std::endl;

    start = clock();
    sortDeque();
    fin = clock();
    deqTime = static_cast<double>(fin - start);

    std::cout << "Time to process a range of " << argVec.size()
     << " elements with std::vector : " << vecTime << "us\n";
    std::cout << "Time to process a range of " << argDeq.size()
     << " elements with std::deque : " << deqTime << "us\n";
*/
}

// 0 1 1 3 5 11 21 ..
// index 22까지만 하는게 좋을걸..
// 임의로 int 최댓값 기준 분기 가능 ?? ㅠㅠ 제발요
void PmergeMe::makeJacobArr() {
	jacobVec.push_back(0);
    jacobVec.push_back(1);

    int end = pairVec.size();
    if (pairVec.size() > 22)
        end = 23;
    for (size_t i = 0; i < end; i++) {
        jacobVec.push_back(jacobVec[i + 1] + 2 * jacobVec[i]);
    }
}

void PmergeMe::sortVector() {
    // 두개씩 묶은 pair로 저장하는데, 첫번째요소는 둘 중 큰 거, 두번째요소는 둘 중 작은 거
	for (size_t i = 0; i < argVec.size() - 1; i += 2) { // n/2번 비교
        if (argVec[i] < argVec[i + 1])
		    this->pairVec.push_back(std::make_pair(argVec[i + 1], argVec[i]));
        else
            this->pairVec.push_back(std::make_pair(argVec[i], argVec[i + 1]));
	}
    // 인자 홀수인 경우 마지막 남은 하나 저장
    int tmp = -1;
    if (argVec.size() % 2 == 1)
        tmp = *(argVec.end() - 1);

    // 큰 요소 기준으로 재귀적으로 정렬해야돼서 sort 못쓸듯 ㅎㅎ;
    std::sort(pairVec.begin(), pairVec.end());

    // 작은배열 맨 첫 값 큰 배열 맨 첫 값보다 항상 작음 => 큰 배열 맨 앞으로
    this->mainVec.push_back(this->pairVec[0].second);
    // 각 pair의 첫 요소는 mainVec에, 두번째 요소는 pendVec에 각각 저장. main은 정렬된 상태
	for (std::size_t i = 0; i < this->pairVec.size(); i++) {
		this->mainVec.push_back(this->pairVec[i].first);
        this->pendVec.push_back(this->pairVec[i].second);
    }

    std::cout << "mainVec : ";
    printVector(mainVec);

    makeJacobArr();
    // 0 1 1 3 5 11 21 .. pendVec의 1번째 요소부터 뽑는다고 할 때,
    // 1, 그 다음 3, 2, 그 다음 5, 4, 그 다음 11 10 9 8 7 6 그 다음 21 ~ 12
    // jacobVec[2]부터 사용하는 건 마즘 근데 그것도 이미 앞에 뒀으니 
    // pend[jacobVec[3]]부터 꺼낼거야
    // pend가 3개 있으면 2번만 꺼내면 되니까 1 < pairVec.size()하고, 

    std::cout << "jacobVec : ";
    printVector(jacobVec);
    std::cout << "pendVec : ";
    printVector(pendVec);

    // pend를 하나씩 빼서 main의 적절한 위치에 넣을 거외다..
    int oldJacob = 1;
    int newJacob;
    for (size_t i = 2; i < pairVec.size(); i++) {
        newJacob = jacobVec[i + 1];
        while (newJacob > oldJacob) {
            if (newJacob - 1 < pairVec.size()) {
                int endIdx = std::find(mainVec.begin(), mainVec.end(), pairVec[newJacob - 1].first) - mainVec.begin();
                bSearchVec(endIdx, pairVec[newJacob - 1].second);
            }
            newJacob--;
        }
        oldJacob = jacobVec[i + 1];
    }
	if (tmp != -1) // 인자로 홀수개 받아서 하나 남을때
		bSearchVec(mainVec.size() - 1, tmp);
}

void PmergeMe::bSearchVec(int end, int value) {
	int start = 0;
    int mid;

	while (start <= end) {
		mid = start + (end - start) / 2;
		if (value > this->mainVec[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	this->mainVec.insert(this->mainVec.begin() + start, value);
}
/*
void PmergeMe::sortDeque() {
}
*/