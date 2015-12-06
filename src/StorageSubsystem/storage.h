#ifndef STORAGE_H
#define STORAGE_H

// DB name
#define DATABASE_NAME "cupid.db"

// Student table
#define STU_TABLE    "students"
#define STU_ID_COL   "id"
#define STU_NAME_COL "name"
// Admin table
#define ADMN_TABLE    "admins"
#define ADMN_ID_COL   "id"
#define ADMN_NAME_COL "name"
// Project table
#define PRO_TABLE       "projects"
#define PRO_ID_COL      "id"
#define PRO_NAME_COL    "name"
#define PRO_MAX_GRP_COL "max_grp_size"
#define PRO_MIN_GRP_COL "min_grp_size"
// Enrollment Table
#define ENRL_TABLE   "enrollment"
#define ENRL_STU_COL "stu"
#define ENRL_PRO_COL "project"
#define ENRL_GRP_COL "group_num"
#define ENRL_GRP_NUM -1             // Default group number for students
// Questions table
#define QSTN_TABLE    "questions"
#define QSTN_ID_COL   "id"
#define QSTN_TEXT_COL "text"
#define QSTN_CAT_COL  "category"
// Answers table
#define ANSR_TABLE   "answers"
#define ANSR_ID_COL  "id"
#define ANSR_QID_COL "question"
#define ANSR_VAL_COL "answer"
// Student's response table
#define RESP_TABLE         "responses"
#define RESP_STU_COL       "stu"
#define RESP_QSTN_COL      "question"
#define RESP_DESR_ANSR_COL "desired"
#define RESP_PSNL_ANSR_COL "personal"

#endif // STORAGE_H
