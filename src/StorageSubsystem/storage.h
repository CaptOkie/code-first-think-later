#ifndef STORAGE_H
#define STORAGE_H

// DB name
#define DATABASE_NAME "cupid.db"

// Student table
#define STU_TABLE    "students"
#define STU_ID_COL   "id"
#define STU_NAME_COL "name"
// Admin table
#define STU_TABLE    "admins"
#define STU_ID_COL   "id"
#define STU_NAME_COL "name"
// Project table
#define PRO_TABLE       "projects"
#define PRO_NAME_COL    "name"
#define PRO_MAX_GRP_COL "max_grp_size"
#define PRO_MIN_GRP_COL "min_grp_size"
// Enrollment Table
#define ENRL_TABLE   "enrollment"
#define ENRL_STU_COL "stu_id"
#define ENRL_PRO_COL "project_name"
// Questions table
#define QSTN_TABLE    "questions"
#define QSTN_ID_COL   "id"
#define QSTN_DESR_COL "desired"
#define QSTN_PSNL_COL "personal"
#define QSTN_CAT_COL  "category"
// Answers table
#define ANSR_TABLE   "answers"
#define ANSR_ID_COL  "id"
#define ANSR_QID_COL "question_id"
#define ANSR_VAL_COL "answer"
// Student's response table
#define RESP_TABLE         "responses"
#define RESP_STU_COL       "student_id"
#define RESP_QSTN_COL      "question_id"
#define RESP_DESR_ANSR_COL "desired_answer_id"
#define RESP_PSNL_ANSR_COL "personal_answer_id"

#endif // STORAGE_H
