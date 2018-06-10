#include "SearchTree.hpp"
using namespace std;
bool SearchTree::isEmpty() const
{
    return (root == NULL);
}

bool SearchTree::isFull() const
{
    NodeAluno* location;
    try
    {
        location = new NodeAluno;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

void SearchTree::destroyTree(NodeAluno*& tree)
{
    if(tree != NULL){
        destroyTree(tree->direita);
        destroyTree(tree->esquerda);
        delete tree;
    }
  
    
}


void SearchTree::retrieveAluno(NodeAluno* tree,  Aluno& aluno, bool& found) const
{
    if (tree == NULL)
        found = false;
    else if (aluno.getRa() < tree->aluno.getRa())
        retrieveAluno(tree->esquerda, aluno, found);
    else if (aluno.getRa() > tree->aluno.getRa())
        retrieveAluno(tree->direita, aluno, found);
    else {
        aluno = tree->aluno;
        found = true;
    }
}

void SearchTree::insertAluno(NodeAluno*& tree, Aluno aluno)
{
    
    if(tree == NULL){
        tree = new NodeAluno();
        tree->aluno = aluno;
        tree->esquerda = NULL;
        tree->direita = NULL;
    }else{
        if (aluno.getRa() < tree->aluno.getRa()){
            insertAluno(tree->esquerda, aluno);
        }else if( aluno.getRa() > tree->aluno.getRa()){
            insertAluno(tree->direita, aluno);
        }
        
    }
}

void SearchTree::deleteAluno(NodeAluno*& tree, Aluno aluno)
{
    if(!isEmpty()){
        
        if(tree == NULL){
           
            return;
        }
        
        if(aluno.getRa() == tree->aluno.getRa() ){
            
            if(tree->esquerda == NULL && tree->direita == NULL){
            
                deleteNodeAluno(tree);
            }else{
                if(tree->esquerda != NULL && tree->direita == NULL){
                    
                    tree = tree->esquerda;
                   
                }
                else if(tree->esquerda== NULL && tree->direita != NULL){
                    tree = tree->direita;
                   
                  
                }
                else if(tree->esquerda!= NULL && tree->direita != NULL){
                    Aluno buffer;
                    getSuccessor(tree->direita, buffer);
                    deleteAluno(tree, buffer);
                    tree->aluno = buffer;
                    
                }
            }
        }
        else{
            if(aluno.getRa() < tree->aluno.getRa() ){
                
                deleteAluno(tree->esquerda,aluno);
            }else if(aluno.getRa() > tree->aluno.getRa() ){
                
                deleteAluno(tree->direita,aluno);
            }
            
        }
        
    }
    
        
       
    

   
}


void SearchTree::deleteNodeAluno(NodeAluno*& tree)
{
       
        tree = NULL;
        delete tree;
    
}

void SearchTree::getSuccessor(NodeAluno* tree, Aluno& data)
{
    if(tree == NULL)
        return;
    if(tree->esquerda == NULL && tree->direita == NULL){
        data = tree->aluno;
       
    }else{
        if(tree->esquerda!= NULL){
            getSuccessor(tree->esquerda, data);
        }
        
    }
}

void SearchTree::printPreOrder(NodeAluno* tree) const
{
    if(tree == NULL)
        return;
        
    cout<< tree->aluno.getRa() <<",";
    printPreOrder(tree->esquerda);
    printPreOrder(tree->direita);
    
    
}

void SearchTree::printInOrder(NodeAluno* tree) const
{
    if(tree == NULL)
        return;
    
   
    printPreOrder(tree->esquerda);
     cout<< tree->aluno.getRa() <<",";
    printPreOrder(tree->direita);
}

void SearchTree::printPostOrder(NodeAluno* tree) const
{
    if(tree == NULL)
        return;
    
    
    printPreOrder(tree->esquerda);
    
    printPreOrder(tree->direita);
    
    cout<< tree->aluno.getRa() <<",";
}
