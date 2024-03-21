
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Variable pour garder une trace du nombre d'étudiants
//int nb_etudiants = 0;
int i = 0;
// Structure pour stoker l'étudiant
//struct Etudiant
struct sinfo {
char fname[50];
char lname[50];
// rool numero etudiant 
int roll;
float cgpa; // note moyenne ponderee 
int cid[10];
} st[55];
// Function to add the student
void add_student()
{
  printf("Add the Students Details\n");
  printf("-------------------------\n");
  printf("Entrer le prenom de l'étudiant\n: ");
  scanf("%s" , st[i].fname);
  printf("Entrer le nom de l'etudiant \n");
  scanf("%s", st[i].lname);
  printf("Entrer le numero etudiant\n");
  scanf("%d", &st[i].roll);
  printf("Entrer le  CGPA qu'il a  obtenu\n");
  scanf("%f", &st[i].cgpa);
  printf("Entrez l'ID de chaque cours\n");
  for (int j = 0; j < 5; j++) {
    scanf("%d",&st[i].cid[j]);
  }
  i = i + 1;
}
//Fonction pour retrouver l'étudiant par le numéro etudiant
void find_student_roll()
{
  int x;
  printf("Entrer le numero etudiant\n");
  scanf("%d", &x);
  for (int j = 1; j <= i; j++) {
    if (x == st[i].roll) {
      printf("les details de l'etudiant sont\n");
      printf("le prenom est  %s\n",st[i].fname);
      printf("le nom est %s\n",st[i].lname);
      printf("le CGPA est %f\n",st[i].cgpa);
      printf("Entrez l'ID de chaque cours\n");
    }
    for (int j = 0; j < 5; j++) {
      printf("Les  ID de cours sont: %d\n",st[i].cid[j]);
    }
  break;
  }
}
// Fonction pour retrouver l'étudiant par le prénom
void find_student_by_name() 
{
  char a[50];
  printf("Entrer le prenom de l'etudiant\n");
  scanf("%s", a);
  for (int j = 1; j <= i; j++) {
    if (!strcmp(st[j].fname, a)) {
      printf("les details de etudiant sont \n");
      printf("le prenom est  %s\n",st[i].fname);
      printf("le nom est %s\n",st[i].lname);
      printf("le numero etudiant est %d\n ",st[i].roll);
      printf("le CGPA est %f\n" ,st[i].cgpa);
      //printf("Enter the course ID of each cours\n");
      for (int j = 0; j < 5; j++) {
        printf("les ID de cours sont%d\n",st[i].cid[j]);
      }
    }else{
      printf("prenom pas trouver\n");
    }
  }
}
// Fonction à trouver les étudiants inscrits dans un cours particulier
void find_student_by_course()
{
  int id;
  printf("Entrer ID de cours \n");
  scanf("%d", &id);
  int c = 0;
  for (int j = 1; j <= i; j++) {
    for (int d = 0; d < 5; d++) {
      if (id == st[j].cid[d]) {
        printf("The Students Details are\n");
        printf("The First name is %s\n",st[i].fname);
        printf("The Last name is %s\n",st[i].lname);
        printf("The Roll Number is %d\n ",st[i].roll);
        printf("The CGPA is %f\n",st[i].cgpa);
        c = 1;
        break;
      }else
      printf("etudiant pas inscrit au cours de id :%d\n",id);
    }
  }
}
//Fonction pour imprimer le nombre total d'étudiants
void count_students()
{
  printf("le nombre total d'etudiants est %d\n", i);
  printf("\n vous pouvez avoir max  50 students\n");
  printf("vous pouvez avoir  %d plus  students\n",50 - i);
}
// Fonction pour supprimer un élève par le numéro etudiant
void delete_student()
{
  int a;
  printf("Entrer le numero etudiant a supprimer\n");
  scanf("%d", &a);
  for (int j = 1; j <= i; j++) {
    if (a == st[j].roll) {
      for (int k = j; k < 49; k++)
        st[k] = st[k + 1];
        i--;
    }
  }
  printf("Numero supprimer avec succés\n");
}
// Fonction pour mettre à jour les données d'un étudiant
void update_student()
{
  printf("entrer le numero pour mettre a jour : ");
  long int x;
  scanf("%ld",&x);
  for (int j = 0; j < i; j++) {
    if (st[j].roll == x) {
      printf("1. first name\n"
            " 2. last name\n"
            " 3. roll no.\n"
            " 4. CGPA\n"
            " 5. courses\n");
      int z;
      scanf("%d",&z);
        switch (z) {  
          case 1:
              printf("Entrer le nouveau prenom : \n");
              scanf("%s", st[j].fname);
              break;
          case 2:
              printf("Entrer le nouveau nom : \n");
              scanf("%s", st[j].lname);
              break;
          case 3:
                printf("Enter le nouveau numero etudiant : \n");
                scanf("%d", &st[j].roll);
                break;
          case 4:
                printf("Enter la nouvelle CGPA : \n");
                scanf("%f", &st[j].cgpa);
                break;
          case 5:
                printf("Enter les nouveaux cours \n");
                scanf("%d%d%d%d%d", &st[j].cid[0],&st[j].cid[1], &st[j].cid[2],&st[j].cid[3], &st[j].cid[4]);
                break;
          default:
                printf("Invalid choice\n");
        }
        printf("Mise a jour avec succés.\n");
    }
  }
}
// Driver code
void main()
{
  int choice, count;
  while (i = 1) {
    printf("La tâche que vous souhaitez effectuer\n");
    printf("1. Ajouter les détails de l'étudiant\n");
    printf("2. Trouver les détails de l'étudiant par numéro etudiant\n");
    printf("3. Trouver l'etudiand par son prenom \n");
    printf("4. Rechercher les détails de l'étudiant par identifiant de cours\n");
  printf("5.Trouvez le nombre total des étudiants\n");
  printf("6. Supprimer les détails des étudiants par numéro etudiant\n");
  printf("7. Mettre à jour les détails des étudiants par numéro etudiant\n");
  printf("8. To Exit\n");
  printf("Entrez votre choix pour trouver la tâche\n");
  scanf("%d", &choice);
  switch (choice) {
    case 1:
          add_student();
          break;
    case 2:
          find_student_roll();
          break;
    case 3:
          find_student_by_name() ;
          break;
    case 4:
          find_student_by_course();
          break;
    case 5:
          count_students();
          break;
    case 6:
          delete_student();
          break;
    case 7:
          update_student();
          break;
    case 8:
          exit(0);
          break;
    }
  }
}