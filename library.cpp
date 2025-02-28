#include "library.h"

#include "CoursesManager.h"

void* Init() {
    LecturesStats::CoursesManager* DS = new LecturesStats::CoursesManager();
    return (void*)DS;
}

StatusType AddCourse(void* DS, int courseID, int numOfClasses) {
    if (DS == NULL) {
        return INVALID_INPUT;
    }
    return static_cast<StatusType>(((LecturesStats::CoursesManager*)DS)
                                       ->AddCourse(courseID, numOfClasses));
}

StatusType RemoveCourse(void* DS, int courseID) {
    if (DS == NULL) {
        return INVALID_INPUT;
    }
    return static_cast<StatusType>(
        ((LecturesStats::CoursesManager*)DS)->RemoveCourse(courseID));
}

StatusType WatchClass(void* DS, int courseID, int classID, int time) {
    if (DS == NULL) {
        return INVALID_INPUT;
    }
    return static_cast<StatusType>(((LecturesStats::CoursesManager*)DS)
                                       ->WatchClass(courseID, classID, time));
}

StatusType TimeViewed(void* DS, int courseID, int classID, int* timeViewed) {
    if (DS == NULL) {
        return INVALID_INPUT;
    }
    return static_cast<StatusType>(
        ((LecturesStats::CoursesManager*)DS)
            ->TimeViewed(courseID, classID, timeViewed));
}

StatusType GetMostViewedClasses(void* DS, int numOfClasses, int* courses,
                                int* classes) {
    if (DS == NULL) {
        return INVALID_INPUT;
    }
    return static_cast<StatusType>(
        ((LecturesStats::CoursesManager*)DS)
            ->GetMostViewedClasses(numOfClasses, courses, classes));
}

void Quit(void** DS) {
    delete ((LecturesStats::CoursesManager*)(*DS));
    *DS = nullptr;
}