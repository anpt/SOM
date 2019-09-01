pipeline {
  agent any
  stages {
    stage('clean') {
      steps {
        sh 'clean worksspace'
      }
    }
    stage('Build') {
      steps {
        dir(path: '/tmp')
      }
    }
  }
}