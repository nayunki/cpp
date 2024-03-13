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
    std::vector<int>::iterator it = vec.begin();
    for (; it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque(std::deque<int> deq) {
    std::deque<int>::iterator it = deq.begin();
    for (; it != deq.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;   
}

void PmergeMe::putArgToCtn(char **argv) {
    int num;
    for (size_t i = 1; argv[i]; i++) {
        for (size_t j = 0; argv[i][j]; j++) {
            if (!std::isdigit(argv[i][j]))
                throw invalidInput();
        }
        num = static_cast<int>(strtod(argv[i], NULL));
        if (num <= 0)
            throw invalidInput();
        this->vec.push_back(num);
        this->deq.push_back(num);
    }
}

// 1 3 5 11 21 ..
void PmergeMe::makeJacobArr() {
	this->jacobVec.push_back(1);
    this->jacobVec.push_back(3);

    for (size_t i = 0; i < 29; i++) { // INT_MAX까지만 !
        this->jacobVec.push_back(this->jacobVec[i + 1] + 2 * this->jacobVec[i]);
    }
}

void PmergeMe::execute(char **argv) {
    putArgToCtn(argv);
    makeJacobArr();

    std::cout << "\n\nBefore: ";
    printVector(vec);

    clock_t start = clock();
    sortVector(vec.size(), 1);
    clock_t fin = clock();
    vecTime = static_cast<double>(fin - start);

    std::cout << "\n\nAfter: ";
    printVector(vec);

    start = clock();
    sortDeque(deq.size(), 1);
    fin = clock();
    deqTime = static_cast<double>(fin - start);

    std::cout << "\n\nTime to process a range of " << vec.size()
     << " elements with std::vector : " << vecTime << "us\n";
    std::cout << "Time to process a range of " << deq.size()
     << " elements with std::deque : " << deqTime << "us\n";
}

size_t PmergeMe::setIndex(size_t currIdx) {
    if (currIdx == 0)
        return 1;
    if (currIdx == 1)
        return 3;
    if (currIdx - 1 == this->jacobVec[jacobIdx]) {
        jacobIdx++;
        return this->jacobVec[jacobIdx + 1];
    }
    return currIdx - 1;
}

////////////////////////////sort vector////////////////////////////

void PmergeMe::bSearchVec(size_t idx, size_t elementSize, std::vector<int> & mainVec, std::vector<int> & pendVec) {
    int start = 0;
    int end = idx + this->insertionCount;
    std::vector<int>::iterator mainIt = mainVec.begin();
    std::vector<int>::iterator pendIt = pendVec.begin() + idx * elementSize;

    while (*pendIt == 0)
        pendIt++;

    // pend의 맨 앞 요소는 항상 main보다 작음
    if (idx == 0) {
        mainVec.insert(mainIt, pendIt, pendIt + elementSize);
        return;
    }

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mainVec[mid * elementSize] < *pendIt)
            start = mid + 1;
        else
            end = mid - 1;
    }
    mainVec.insert(mainIt + start * elementSize, pendIt, pendIt + elementSize);
    this->insertionCount++;
}

void PmergeMe::insertVec(size_t pairCount, size_t elementSize) {
    this->jacobIdx = 0;
    this->insertionCount = 0;

    std::vector<int> mainVec;
    std::vector<int> pendVec;
    std::vector<int>::iterator it = this->vec.begin();
    for (size_t i = 0; i < pairCount; i++) {
        if (i % 2 == 1 || i == pairCount - 1)
            pendVec.insert(pendVec.end(), it + i * elementSize, it + (i + 1) * elementSize);
            // vec.insert(pos, first, last) : first부터 last 전까지 원소들을 pos에 삽입
        else
            mainVec.insert(mainVec.end(), it + i * elementSize, it + (i + 1) * elementSize);
    }

    size_t idx = 0;
    size_t pendVecLen = pairCount / 2 + pairCount % 2;
    for (size_t i = 0; i < pendVecLen; i++) {
        idx = setIndex(idx);
        if (idx >= pendVecLen)
            idx = pendVecLen;
        bSearchVec(idx - 1, elementSize, mainVec, pendVec);
    }
    this->vec = mainVec;
}

void PmergeMe::sortVector(size_t pairCount, size_t elementSize) {
    if (pairCount == 1)
        return ;

    for (size_t i = 0; i < pairCount; i += 2) {
        std::vector<int>::iterator first = this->vec.begin() + i * elementSize;
        std::vector<int>::iterator second = this->vec.begin() + (i + 1) * elementSize;
        if (*first < *second)
            // swap_ranges(first, last, swapFirst) : first부터 last를 swapFirst부터 last-first 만큼 swap
            std::swap_ranges(first, second, second);
    }
    sortVector(pairCount / 2, elementSize * 2);
    insertVec(pairCount, elementSize);
}

////////////////////////////sort deque////////////////////////////

void PmergeMe::bSearchDeq(size_t idx, size_t elementSize, std::deque<int> & mainDeq, std::deque<int> & pendDeq) {
    int start = 0;
    int end = idx + this->insertionCount;
    std::deque<int>::iterator mainIt = mainDeq.begin();
    std::deque<int>::iterator pendIt = pendDeq.begin() + idx * elementSize;

    while (*pendIt == 0)
        pendIt++;

    if (idx == 0) {
        mainDeq.insert(mainIt, pendIt, pendIt + elementSize);
        return;
    }

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mainDeq[mid * elementSize] < *pendIt)
            start = mid + 1;
        else
            end = mid - 1;
    }
    mainDeq.insert(mainIt + start * elementSize, pendIt, pendIt + elementSize);
    this->insertionCount++;
}

void PmergeMe::insertDeq(size_t pairCount, size_t elementSize) {
    this->jacobIdx = 0;
    this->insertionCount = 0;

    std::deque<int> mainDeq;
    std::deque<int> pendDeq;
    std::deque<int>::iterator it = this->deq.begin();
    for (size_t i = 0; i < pairCount; i++) {
        if (i % 2 == 1 || i == pairCount - 1)
            pendDeq.insert(pendDeq.end(), it + i * elementSize, it + (i + 1) * elementSize);
        else
            mainDeq.insert(mainDeq.end(), it + i * elementSize, it + (i + 1) * elementSize);
    }

    size_t idx = 0;
    size_t pendDeqLen = pairCount / 2 + pairCount % 2;
    for (size_t i = 0; i < pendDeqLen; i++) {
        idx = setIndex(idx);
        if (idx >= pendDeqLen)
            idx = pendDeqLen;
        bSearchDeq(idx - 1, elementSize, mainDeq, pendDeq);
    }
    deq = mainDeq;
}

void PmergeMe::sortDeque(size_t pairCount, size_t elementSize) {
    if (pairCount == 1)
        return ;

    std::deque<int>::iterator it = this->deq.begin();
    for (size_t i = 0; i < pairCount; i += 2) {
        std::deque<int>::iterator first = it + i * elementSize;
        std::deque<int>::iterator second = it + (i + 1) * elementSize;
        if (*first < *second)
            std::swap_ranges(first, second, second);
    }
    sortDeque(pairCount / 2, elementSize * 2);
    insertDeq(pairCount, elementSize);
}
